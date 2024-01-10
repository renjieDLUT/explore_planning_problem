import torch
import torchvision.models
from torch import nn as nn
from collections import OrderedDict
import math
import torch.utils.data
import time


class MyEncoderBlock(nn.Module):
    def __init__(self, num_heads, hidden_dim, mlp_dim, norm_layer, dropout, attention_dropout):
        super(MyEncoderBlock, self).__init__()
        self.ln_1 = norm_layer(hidden_dim)
        self.self_attention = nn.MultiheadAttention(hidden_dim, num_heads, dropout=attention_dropout, batch_first=True)
        self.dropout = nn.Dropout(dropout)

        self.ln_2 = norm_layer(hidden_dim)
        self.mlp = torchvision.ops.MLP(in_channels=hidden_dim, hidden_channels=[mlp_dim, hidden_dim],
                                       activation_layer=nn.GELU, dropout=dropout)

    def forward(self, input):
        assert input.dim() == 3, f"Expected (batch_size, seq_length, hidden_dim) got {input.shape}"
        x = self.ln_1(input)
        x, _ = self.self_attention(x, x, x, need_weights=False)
        x = self.dropout(x)
        x = x + input

        y = self.ln_2(x)
        y = self.mlp(y)
        return x + y


class MyVITEncoder(nn.Module):
    def __init__(
            self,
            seq_length: int,
            num_layers: int,
            num_heads: int,
            hidden_dim: int,
            mlp_dim: int,
            dropout: float,
            attention_dropout: float,
            norm_layer,
    ):
        super(MyVITEncoder, self).__init__()
        self.pos_embedding = nn.Parameter(torch.empty(1, seq_length, hidden_dim).normal_(std=0.02))
        self.dropout = nn.Dropout(dropout)
        layers: OrderedDict[str, nn.Module] = OrderedDict()

        for i in range(num_layers):
            layers[f"encoder_layer_{i}"] = MyEncoderBlock(num_heads, hidden_dim, mlp_dim, norm_layer, dropout=dropout,
                                                          attention_dropout=attention_dropout)

        self.layers = nn.Sequential(layers)
        self.ln = norm_layer(hidden_dim)

    def forward(self, input):
        input = input + self.pos_embedding
        return self.ln(self.layers(self.dropout(input)))


class MyVIT(nn.Module):
    def __init__(self, image_size: int = 224, patch_size: int = 16, hidden_dim: int = 768, mlp_dim: int = 3072,
                 attention_dropout: float = 0.0, dropout: float = 0.0, num_classes: int = 1000,
                 num_layer=12, num_heads=3):
        super(MyVIT, self).__init__()
        self.image_size = image_size
        self.patch_size = patch_size
        self.hidden_dim = self.patch_size ** 2 * 3 if hidden_dim is None else hidden_dim
        self.mlp_dim = mlp_dim
        self.attention_dropout = attention_dropout
        self.dropout = dropout
        self.num_classes = num_classes

        # self.conv_proj1 = nn.Conv2d(in_channels=3, out_channels=self.hidden_dim, kernel_size=patch_size,
        #                             stride=patch_size)
        self.conv_proj1 = nn.Conv2d(in_channels=3, out_channels=16, kernel_size=3,
                                    stride=1, padding=1)
        self.bn1 = nn.BatchNorm2d(16)
        self.relu = nn.ReLU()
        self.conv_proj2 = nn.Conv2d(in_channels=16, out_channels=64, kernel_size=3,
                                    stride=1, padding=1)
        self.bn2 = nn.BatchNorm2d(64)
        self.conv_proj3 = nn.Conv2d(64, self.hidden_dim, kernel_size=patch_size, stride=patch_size)

        self.class_token = nn.Parameter(torch.zeros(1, 1, hidden_dim))
        seq_length = (image_size // patch_size) ** 2

        self.seq_length = seq_length + 1

        self.encoder = MyVITEncoder(self.seq_length, num_layer, num_heads, self.hidden_dim, self.mlp_dim, dropout,
                                    attention_dropout, nn.LayerNorm)

        heads_layers: OrderedDict[str, nn.Module] = OrderedDict()
        heads_layers["head"] = nn.Linear(hidden_dim, num_classes)
        self.heads = nn.Sequential(heads_layers)

        for conv in [self.conv_proj1, self.conv_proj2, self.conv_proj3]:
            fan_in = conv.in_channels * conv.kernel_size[0] * conv.kernel_size[1]
            nn.init.trunc_normal_(conv.weight, std=math.sqrt(1 / fan_in))
            if conv.bias is not None:
                nn.init.zeros_(conv.bias)

        nn.init.zeros_(self.heads.head.weight)
        nn.init.zeros_(self.heads.head.bias)

    def _process_input(self, x: torch.Tensor) -> torch.Tensor:
        n, c, h, w = x.shape

        n_h = h // self.patch_size
        n_w = w // self.patch_size

        x = self.relu(self.bn1(self.conv_proj1(x)))
        x = self.relu(self.bn2(self.conv_proj2(x)))
        x = self.conv_proj3(x)
        assert x.shape[2] == n_h, "x.shape[3]==n_h"
        assert x.shape[3] == n_w, "x.shape[3]==n_w"

        x = x.reshape(n, self.hidden_dim, n_h * n_w)

        x = x.permute(0, 2, 1)
        return x

    def forward(self, input: torch.Tensor):
        x = self._process_input(input)
        n = x.shape[0]
        batch_class_token = self.class_token.expand(n, -1, -1)
        x = torch.cat([batch_class_token, x], dim=1)

        x = self.encoder(x)

        x = x[:, 0]

        x = self.heads(x)

        return x


if __name__ == "__main__":
    classes = ['plane', 'car', 'bird', 'cat', 'deer',
               'dog', 'frog', 'horse', 'ship', 'truck']
    #  =================================== data ================================
    norm_mean = [0.485, 0.456, 0.406]
    norm_std = [0.229, 0.224, 0.225]
    train_transform = torchvision.transforms.Compose(
        [torchvision.transforms.RandomHorizontalFlip(),
         torchvision.transforms.RandomVerticalFlip(),
         torchvision.transforms.RandomResizedCrop(32, scale=(0.8, 1.0)),
         torchvision.transforms.ToTensor(),
         torchvision.transforms.Normalize(norm_mean, norm_std)])
    test_transform = torchvision.transforms.Compose(
        [torchvision.transforms.ToTensor(),
         torchvision.transforms.Normalize(norm_mean, norm_std)])
    train_dataset = torchvision.datasets.CIFAR10(
        './data/cifar10', train=True, transform=train_transform, download=True)

    test_dataset = torchvision.datasets.CIFAR10(
        './data/cifar10', train=False, transform=test_transform, download=True)

    batch_size = 64
    train_dataloader = torch.utils.data.DataLoader(train_dataset, batch_size=batch_size, shuffle=True, num_workers=6)
    test_dataloader = torch.utils.data.DataLoader(test_dataset, batch_size=batch_size, num_workers=6)

    # =================================== model =========================
    net = MyVIT(image_size=32, patch_size=4, hidden_dim=92, mlp_dim=192, num_classes=10, num_layer=8, num_heads=1,
                dropout=0.0, attention_dropout=0.0)
    param_count = 0
    for name, param in net.named_parameters():
        param_count += param.numel()
        print(name, param.shape)
    print("net param count:{:,d}".format(param_count))

    # ======================================== loss function =======================================
    loss_fn = torch.nn.CrossEntropyLoss()

    # ========================================= optimizer =============================================
    LR = 0.05
    MOMENTA = 0.9
    lr_schedular_step = 20
    lr_decay_gamma = 0.8

    optimizer = torch.optim.SGD(net.parameters(), lr=LR, momentum=MOMENTA)
    lr_schedular = torch.optim.lr_scheduler.StepLR(optimizer, 5, gamma=lr_decay_gamma)

    # ============================================= 训练 ======================================
    epochs = 500
    device = torch.device("cuda" if torch.cuda.is_available() else "cpu")
    print(device)
    # device=torch.device("cpu")
    train_size = len(train_dataset)
    test_size = len(test_dataset)
    net.to(device)

    for epoch in range(1, epochs + 1):
        loss_value, count = 0., 0
        time_tic = time.time()
        for x, y in train_dataloader:
            x, y = x.to(device), y.to(device)
            # with torch.autocast(device_type='cuda', dtype=torch.float16):
            y_hat: torch.Tensor = net(x)
            loss = loss_fn(y_hat, y)
            loss.backward()
            optimizer.step()
            optimizer.zero_grad()

            loss_value += loss.item()
            count += (y_hat.argmax(dim=1) == y).sum()
        lr_schedular.step()
        time_toc = time.time()
        print("epoch:{}   loss:{}    acurracy:{}    cost time:".format(epoch, loss_value / train_size,
                                                                       count / train_size),
              time_toc - time_tic)

        loss_value, count = 0., 0
        for x, y in test_dataloader:
            x, y = x.to(device), y.to(device)
            y_hat: torch.Tensor = net(x)
            loss = loss_fn(y_hat, y)

            loss_value += loss.item()
            count += (y_hat.argmax(dim=1) == y).sum()

        print("epoch:{}    loss:{}    acurracy:{}".format(epoch, loss_value / test_size,
                                                          count / test_size))
