# =================================scalar scalars histogram====================
import torch
import torchvision.utils
# import numpy as np
# from torch.utils.tensorboard import SummaryWriter
# import matplotlib.pyplot as plt
# writer = SummaryWriter(comment='test_tensorboard')
#
# for x in range(100):
#     writer.add_scalar('y=2x', x * 2, x)
#     writer.add_scalar('y=pow(2, x)', 2 ** x, x)
#
#     writer.add_scalars('data/scalar_group', {"xsinx": x * np.sin(x),
#                                              "xcosx": x * np.cos(x),
#                                              "arctanx": np.arctan(x)}, x)
# for i in range(20):
#     data=np.random.normal(size=1000)
#     # data=np.arange(1000)
#     writer.add_histogram("histogram1",data,i)
#     plt.subplot(121).hist(data,label="uniform")
#     plt.show()
# writer.close()

# # ================================= image ====================
# from torch.utils.tensorboard import SummaryWriter
#
# writer = SummaryWriter(comment="image", filename_suffix="fake_image")
# fake_img = torch.randn(3, 255, 255)
# writer.add_image("fake_img", fake_img, 1)
#
# fake_img = torch.ones((3, 255, 255))
# writer.add_image("fake_img", fake_img, 2)
#
# fake_img = torch.ones((3, 255, 255)) * 1.1
# writer.add_image("fake_img", fake_img, 3)
#
# fake_img = torch.rand((255, 255))
# writer.add_image("fake_img", fake_img, 4, dataformats="HW")
#
# fake_img = torch.ones((255, 255, 3))
# writer.add_image("fake_img", fake_img, 5, dataformats="HWC")
#
# writer.close()

# # ================================== make grid=================
#
# from torchvision.utils import make_grid
# from test.pytorch_test.rmb_project.utils.rmb_dataset import RMBDataset
# from torch.utils.data import DataLoader
# from torch.utils.tensorboard import SummaryWriter
# from torchvision.transforms import  transforms
#
# path = './data/split_data/test'
# transform_compose = transforms.Compose([transforms.Resize((32, 64)), transforms.ToTensor()])
# dataset = RMBDataset(path, transform_compose)
# loader = DataLoader(dataset, batch_size=16)
# imgs, labels = next(iter(loader))
# img_grid = make_grid(imgs, 4)
#
# writer = SummaryWriter(comment="make_grid")
# writer.add_image("img", img_grid,1)
# writer.close()


# # ================================== graph =================
#
# from test.pytorch_test.rmb_project.model import my_lenet
# from torch.utils.tensorboard import SummaryWriter
#
# net = my_lenet.LeNetSequential(2)
# writer = SummaryWriter(comment="_graph")
# input_data = torch.randn(1, 3, 32, 32)
# writer.add_graph(net, input_data)
# writer.close()

# ====================================== visualization kernel ==============

from torchvision.models import AlexNet, alexnet
from torch.nn import Conv2d
from torch.utils.tensorboard import SummaryWriter
import torchvision
from torchvision.transforms import transforms
import ssl

ssl._create_default_https_context = ssl._create_unverified_context
net = alexnet(pretrained=True)
count = 0
writer = SummaryWriter(comment="alexnet")
for module in net.modules():
    if isinstance(module, Conv2d):
        kernel = module.weight
        out_size, input_size, k_w, k_h = tuple(kernel.shape)
        print(kernel.shape)
        for o_idx in range(out_size):
            kernel_idx = kernel[o_idx, :, :, :].unsqueeze(1)  # make_grid需要 BCHW，这里拓展C维度
            kernel_grid = torchvision.utils.make_grid(kernel_idx, normalize=True, scale_each=True, nrow=input_size)
            writer.add_image('{}_Convlayer_split_in_channel'.format(count), kernel_grid, global_step=o_idx)
        kernel_all = kernel.view(-1, 3, k_h, k_w)  # 3, h, w
        kernel_grid = torchvision.utils.make_grid(kernel_all, normalize=True, scale_each=True, nrow=8)  # c, h, w
        writer.add_image('{}_all'.format(count), kernel_grid, global_step=322)
        break

img_path = './test/pytorch_test/res/lena.png'

from PIL import Image

img = Image.open(img_path).convert('RGB')
transform = transforms.Compose((transforms.Resize((224, 224)), transforms.ToTensor(), transforms.Normalize(0.5, 0.25)))
img_tensor = transform(img).unsqueeze(0)
layer1 = net.features[0]
feature_tensor: torch.Tensor = layer1(img_tensor)

feature_map = feature_tensor.transpose(0, 1)
imgs = torchvision.utils.make_grid(feature_map, 8, normalize=True)
writer.add_image('feature_map', imgs, global_step=3)
writer.close()
