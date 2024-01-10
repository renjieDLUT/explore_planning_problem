# hook 函数机制,不改变主体,实现额外功能
import copy

import torch.nn
import torchvision.utils
# # ======================== tensor hook =====================
# import torch
#
# x = torch.tensor([1.])
# w = torch.tensor([1.], requires_grad=True)
# a = torch.add(w, x)
# b = torch.add(w, 1.)
# y = torch.mul(a, b)
#
# a_grad = list()
#
#
# def grad_fn(grad: torch.Tensor):
#     a_grad.append(grad)
#
#
# def w_grad_fn(grad: torch.Tensor):
#     grad *= 3
#
#
# a.register_hook(grad_fn)
# w.register_hook(w_grad_fn)
#
# y.backward()
#
# print("gradient:", x.grad, w.grad, a.grad, b.grad, y.grad)
# print("a_grad:", a_grad[0])


# # ============================== forward_hook, forward_pre_hook, backward_hook=============
#
# import torch
#
#
# class Net(torch.nn.Module):
#     def __init__(self):
#         super(Net, self).__init__()
#         self.conv1 = torch.nn.Conv2d(1, 2, 3)
#         self.conv2 = torch.nn.Conv2d(2, 3, 3)
#
#     def forward(self, x):
#         x = self.conv1(x)
#         return self.conv2(x)
#
#
# def forward_hook(module, input_data, out_data):
#     print("forward_hook", input_data, out_data)
#
#
# def forward_pre_hook(module, input_data):
#     print("forward_pre_hook", input_data)
#
#
# def backward_hook(module, input_grad, output_grad):
#     print("backward_hook", input_grad, output_grad)
#
#
# net = Net()
# net.conv1.weight[0].detach().fill_(1)
# net.conv1.weight[1].detach().fill_(2)
# net.conv1.bias.data.detach().zero_()
#
# net.conv2.weight[0].detach().fill_(1)
# net.conv2.weight[1].detach().fill_(2)
# net.conv2.bias.data.detach().fill_(2)
#
# net.register_forward_hook(forward_hook)
# net.register_forward_pre_hook(forward_pre_hook)
# net.register_backward_hook(backward_hook)
#
# data = torch.zeros(1, 1, 5, 5)
# y_hat = net(data)
#
# y = torch.zeros(1, 3, 1, 1)
# loss_fn = torch.nn.MSELoss()
# loss = loss_fn(y_hat, y)
# loss.backward()


# =============================== feature map visualization =================

from torch.utils.tensorboard import SummaryWriter
import torchvision.models as models
import torchvision.transforms as transforms
from PIL import Image

path_img = "./lena.png"  # your path to image
normMean = [0.49139968, 0.48215827, 0.44653124]
normStd = [0.24703233, 0.24348505, 0.26158768]

norm_transform = transforms.Normalize(normMean, normStd)
img_transform = transforms.Compose((transforms.Resize((224, 224)), transforms.ToTensor(), norm_transform))
img_path = './test/pytorch_test/res/lena.png'
img = Image.open(img_path).convert("RGB")

writer = SummaryWriter(comment="feature map visual", filename_suffix="feature")

alex = models.alexnet(pretrained=True)

fmap_dict = dict()
for name, model in alex.named_modules():
    if isinstance(model, torch.nn.Conv2d) and "features" in name:
        key_name = str(model.weight.shape)
        fmap_dict.setdefault(key_name, list())


        def forward_hook(m, i, o):
            key_name = str(m.weight.shape)
            fmap_dict[key_name].append(o)


        n1, n2 = name.split('.')
        model.register_forward_hook(forward_hook)

img_tensor: torch.Tensor = img_transform(img)
img_tensor.unsqueeze_(dim=0)
output = alex(img_tensor)

for k, v in fmap_dict.items():
    fmap: torch.Tensor = v[0]
    fmap.transpose_(0, 1)
    imgs = torchvision.utils.make_grid(fmap)
    writer.add_image(k,imgs)
