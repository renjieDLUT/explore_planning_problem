import sys

import torch.utils.data
import torchvision
import time
from ant_dataset import *
import ssl
import PIL.Image as Image
# import matplotlib.pyplot as plt

ssl._create_default_https_context = ssl._create_unverified_context

# ======================================= 数据 ====================================
train_path = "../dive_into_dl/data/bee_proj/train"
test_path = "../dive_into_dl/data/bee_proj/val"

norm_mean = [0.485, 0.456, 0.406]
norm_std = [0.229, 0.224, 0.225]
train_transform = torchvision.transforms.Compose(
    [torchvision.transforms.Resize((224, 224)),
     torchvision.transforms.RandomHorizontalFlip(),
     torchvision.transforms.ToTensor(),
     torchvision.transforms.Normalize(norm_mean, norm_std)])
test_transform = torchvision.transforms.Compose(
    [torchvision.transforms.Resize((224, 224)),
     torchvision.transforms.ToTensor(),
     torchvision.transforms.Normalize(norm_mean, norm_std)])
train_dataset = AntDataset(train_path, train_transform)
test_dataset = AntDataset(test_path, test_transform)

train_dataset = torchvision.datasets.CIFAR10(
    './data/cifar10', train=True, transform=train_transform, download=True)

test_dataset = torchvision.datasets.CIFAR10(
    './data/cifar10', train=False, transform=test_transform, download=True)

batch_size = 12
train_dataloader = torch.utils.data.DataLoader(train_dataset, batch_size=batch_size, shuffle=True, num_workers=6)
test_dataloader = torch.utils.data.DataLoader(test_dataset, batch_size=batch_size, num_workers=6)

# ======================================== 模型 =========================================
alex = torchvision.models.AlexNet()
resnet18 = torchvision.models.resnet18()
resnet50 = torchvision.models.resnet50()
resnet101 = torchvision.models.resnet101()
vgg16 = torchvision.models.vgg16(pretrained=False)

googlenet = torchvision.models.googlenet()

vit_base_16 = torchvision.models.vit_b_16(weights=torchvision.models.ViT_B_16_Weights)

swin_b=torchvision.models.swin_b()
# model_param = torch.load("./test/pytorch_test/bee_project/res/finetune_resnet18-5c106cde.pth")
# resnet18.load_state_dict(model_param)

classes = ['plane', 'car', 'bird', 'cat', 'deer',
           'dog', 'frog', 'horse', 'ship', 'truck']

# flag = False
# if flag:
#     img_tensor, label = next(iter(train_dataset))
#     plt.subplot(2, 2, 1).hist(img_tensor.flatten())
#     img_tensor = img_tensor.transpose_(dim0=0, dim1=1).transpose_(dim0=1, dim1=2) * 100
#     plt.subplot(2, 2, 2).hist(img_tensor.flatten())
#     Image.fromarray(img_tensor.numpy().astype("uint8")).convert("RGB")

#     print(classes[label])
#     sys.exit()

# net = resnet18
net = vit_base_16

param_count = 0
for param in alex.parameters():
    param_count += param.numel()
print("AlexNet param count:{:,d}".format(param_count))

param_count = 0
for param in vgg16.parameters():
    param_count += param.numel()
print("VGG16 param count:{:,d}".format(param_count))

param_count = 0
for param in resnet18.parameters():
    param_count += param.numel()
print("ResNet18 param count:{:,d}".format(param_count))

for name,param in vit_base_16.named_parameters():
    print(name, param.shape)

param_count = 0
for param in resnet50.parameters():
    param_count += param.numel()
print("ResNet50 param count:{:,d}".format(param_count))

param_count = 0
for param in resnet101.parameters():
    param_count += param.numel()
print("ResNet101 param count:{:,d}".format(param_count))

param_count = 0
for param in googlenet.parameters():
    param_count += param.numel()
print("GoogLeNet param count:{:,d}".format(param_count))

param_count = 0
for param in vit_base_16.parameters():
    param_count += param.numel()
print("ViT_Base_16 param count:{:,d}".format(param_count))

param_count=0
for param in swin_b.parameters():
    param_count+=param.numel()
print("swin_b param count:{:,d}".format(param_count))


# for module in net.modules():
#     print(module)

# for param in net.parameters():
#     param.requires_grad_(False)

if isinstance(net, torchvision.models.ResNet):
    fc_in_num = net.fc.in_features
    net.fc = torch.nn.Linear(fc_in_num, 10)

    net.maxpool = torch.nn.Identity()
    net.conv1 = torch.nn.Conv2d(3, 64, 5)

if isinstance(net, torchvision.models.VGG):
    fc_in_num = net.classifier[6].in_features
    net.classifier[6] = torch.nn.Linear(fc_in_num, 10)
# ======================================== loss function =======================================
loss_fn = torch.nn.CrossEntropyLoss()

# ======================================== 优化器 ============================================
LR = 0.001
MOMENTA = 0.9
lr_schedular_step = 5
lr_decay_gamma = 0.8

optimizer = torch.optim.SGD(net.parameters(), lr=LR, momentum=MOMENTA)
# optimizer = torch.optim.SGD([{"params": net.fc.parameters(), "lr": LR * 0.1}], lr=LR, momentum=MOMENTA)
lr_schedular = torch.optim.lr_scheduler.StepLR(optimizer, 5, gamma=lr_decay_gamma)

# ============================================= train ======================================
epochs = 100
device = torch.device("cuda" if torch.cuda.is_available() else "cpu")
# device=torch.device("cpu")
train_size = len(train_dataset)
test_size = len(test_dataset)
net.to(device)

# checkpoint = torch.load("./test/pytorch_test/bee_project/res/checkpoint_resnet18_70.pkl")
# net.load_state_dict(checkpoint["model_state_dict"])
# optimizer.load_state_dict(checkpoint["optimizer_state_dict"])


# import test.pytorch_test.rmb_project.tools.transform_invert as transform_invert

for epoch in range(1, epochs + 1):
    loss_value, count = 0., 0
    time_tic = time.time()
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
        # res=(y_hat.argmax(dim=1)==y)
        # for i in range(res.shape[0]):
        #     if res[i].item()==False:
        #         img_tensor=x[i]
        #         img=transform_invert.transform_invert(img_tensor,test_transform)
        #         plt.imshow(img)
        #         plt.show()
        #
        #         print(classes[y_hat[i].argmax()])
        #         print(y_hat[i],y_hat[i].argmax(),y[i])

    print("epoch:{}    loss:{}    acurracy:{}".format(epoch, loss_value / test_size,
                                                      count / test_size))
    checkpoint_path = "./test/pytorch_test/bee_project/res/checkpoint_vit_b_16"
    if epoch % 2 == 0:
        checkpoint_path += "_{}.pkl".format(epoch)
        checkpoint = {"model_state_dict": net.state_dict(), "optimizer_state_dict": optimizer.state_dict(),
                      "lr_schedular_state_dict": lr_schedular.state_dict()}
        torch.save(checkpoint, checkpoint_path)
