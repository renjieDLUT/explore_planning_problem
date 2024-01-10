import torch
from torch.nn import Module, Parameter
import torch.nn.functional as functional


def reverse_repeat_tuple(t, n):
    r"""Reverse the order of `t` and repeat each element for `n` times.

    This can be used to translate padding arg used by Conv and Pooling modules
    to the ones used by `F.pad`.
    """
    return tuple(x for x in reversed(t) for _ in range(n))


class MyConv(Module):
    def __init__(self, in_feature: int, out_feature: int, kernel: int, padding_mode: str = 'replicate', device=None,
                 dtype=None):
        super(MyConv, self).__init__()
        factory_kwargs = {'device': device, 'dtype': dtype}
        self.in_feature = in_feature
        self.out_feature = out_feature
        self.kernel = kernel
        self.stride = kernel
        self.dilation1 = 1
        self.dilation2 = 2
        self.dilation3 = 3
        self.padding1 = (0, 0)
        self.padding2 = (1, 1)
        self.padding3 = (2, 2)
        self.padding_mode = padding_mode

        self.reversed_padding_repeated_twice1 = reverse_repeat_tuple(self.padding1, 2)
        self.reversed_padding_repeated_twice2 = reverse_repeat_tuple(self.padding2, 2)
        self.reversed_padding_repeated_twice3 = reverse_repeat_tuple(self.padding3, 2)

        self.weight = Parameter(torch.randn(out_feature, in_feature, kernel, kernel, **factory_kwargs))
        self.bias = Parameter(torch.zeros(out_feature, **factory_kwargs))

    def forward(self, x):
        # noise=torch.normal(0.,0.01,self.weight.size()).to(self.weight.device)
        # self.weight.data+=noise
        x1 = functional.conv2d(x, self.weight, bias=self.bias, stride=self.stride, padding=self.padding1,
                               dilation=self.dilation1,
                               groups=1)
        x2 = functional.conv2d(functional.pad(x, self.reversed_padding_repeated_twice2, mode=self.padding_mode),
                               self.weight.contiguous(), bias=self.bias.contiguous(), stride=self.stride,
                               padding=self.padding1,
                               dilation=self.dilation2,
                               groups=1)
        x3 = functional.conv2d(functional.pad(x, self.reversed_padding_repeated_twice3, mode=self.padding_mode),
                               self.weight.contiguous(), bias=self.bias.contiguous(), stride=self.stride,
                               padding=self.padding1,
                               dilation=self.dilation3,
                               groups=1)

        x = x1 + x2 + x3
        return x


class MyModule(Module):
    def __init__(self):
        super(MyModule, self).__init__()
        self.conv1 = MyConv(3, 30, 3)
        self.conv2 = MyConv(30, 90, 3)
        self.conv3 = MyConv(90, 270, 3)
        self.bn1 = torch.nn.BatchNorm2d(30)
        self.bn2 = torch.nn.BatchNorm2d(90)
        self.bn3 = torch.nn.BatchNorm2d(270)

        self.fc1 = torch.nn.Linear(360, 100)
        self.fc2 = torch.nn.Linear(100, 10)

        self.bn4 = torch.nn.BatchNorm2d(100)
        self.bn5 = torch.nn.BatchNorm2d(10)
        self.pool1 = torch.nn.MaxPool2d(9, 9)
        self.pool2 = torch.nn.MaxPool2d(3, 3)

    def forward(self, x):
        x = functional.relu(self.bn1(self.conv1(x)))
        x1 = self.pool1(x)
        x1 = x1.squeeze()
        x = functional.relu(self.bn2(self.conv2(x)))
        x2 = self.pool2(x)
        x2 = x2.squeeze()
        x = functional.relu(self.bn3(self.conv3(x)))
        x = x.squeeze()
        x = torch.cat([x,  x2], dim=1)
        x = x.view(-1, 360)
        x = functional.relu(self.fc1(x))
        x = self.fc2(x)
        return x


import torchvision
import time

#     ======================== data cifar-10 ==================
transform = torchvision.transforms.Compose(
    [torchvision.transforms.Resize((27, 27)), torchvision.transforms.ToTensor(),
     torchvision.transforms.Normalize([0.5, 0.5, 0.5], [0.5, 0.5, 0.5])])
train_dataset = torchvision.datasets.CIFAR10(
    './test/pytorch_test/bee_project/data', transform=transform, train=True, download=True)

test_dataset = torchvision.datasets.CIFAR10(
    './test/pytorch_test/bee_project/data', transform=transform, train=False, download=True)

batch_size = 100
train_dataloader = torch.utils.data.DataLoader(train_dataset, batch_size=batch_size, shuffle=True, num_workers=4)
test_dataloader = torch.utils.data.DataLoader(test_dataset, batch_size=batch_size, num_workers=4)

# ========================== model =======================
net = MyModule()

count = 0
for param in net.parameters():
    count += param.numel()
print(count)

# ============================== loss function =======================
loss_fn = torch.nn.CrossEntropyLoss()

# ========================= optimizer =============================
LR = 0.001
MOMENTA = 0.9
lr_schedular_step = 5
lr_decay_gamma = 0.9

optimizer = torch.optim.SGD(net.parameters(), lr=LR, momentum=MOMENTA)
lr_schedular = torch.optim.lr_scheduler.StepLR(optimizer, 5, gamma=lr_decay_gamma)

# ============================================= train ======================================
epochs = 1000
device = torch.device("cuda" if torch.cuda.is_available() else "cpu")
# device=torch.device("cpu")
train_size = len(train_dataset)
test_size = len(test_dataset)
net.to(device)

# checkpoint = torch.load("./test/pytorch_test/bee_project/res/checkpoint_10.pkl")
# net.load_state_dict(checkpoint["model_state_dict"])
# optimizer.load_state_dict(checkpoint["optimizer_state_dict"])

checkpoint_path = "./test/pytorch_test/bee_project/res/checkpoint"

for epoch in range(1, epochs + 1):
    loss_value, count = 0., 0
    time_tic = time.time()
    # for name,modul in net.named_modules():
    #     if name=="conv1":
    #         print(modul.weight)
    for x, y in train_dataloader:
        x, y = x.to(device), y.to(device)
        with torch.autocast(device_type='cuda', dtype=torch.float16):
            y_hat: torch.Tensor = net(x)
        loss = loss_fn(y_hat, y)
        loss.backward()
        optimizer.step()
        optimizer.zero_grad()

        loss_value += loss.item()
        count += (y_hat.argmax(dim=1) == y).sum()
    lr_schedular.step()
    time_toc = time.time()
    print("epoch:{}   loss:{}    acurracy:{}    cost time:".format(epoch, loss_value / train_size, count / train_size),
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
    if epoch % 10 == 0:
        checkpoint_path += "_{}.pkl".format(epoch)
        checkpoint = {"model_state_dict": net.state_dict(), "optimizer_state_dict": optimizer.state_dict(),
                      "lr_schedular_state_dict": lr_schedular.state_dict()}
        torch.save(checkpoint, checkpoint_path)
