# -*- utf-8 -*-
import os
import sys

import torch
from torch.utils.data.dataloader import DataLoader
import numpy as np
import torchvision.transforms as transforms
from PIL import Image
from test.pytorch_test.rmb_project import rmb_dataset
import matplotlib.pyplot as plt


def transform_invert(img_tensor: torch.Tensor, transform: transforms.Compose):
    if 'Normalize' in str(transform):
        norm_tranforms = list(filter(lambda x: isinstance(x, transforms.Normalize), transform.transforms))
        norm_tranform = norm_tranforms[0]
        mean = torch.tensor(norm_tranform.mean, dtype=img_tensor.dtype, device=img_tensor.device)
        std = torch.tensor(norm_tranform.std, dtype=img_tensor.dtype, device=img_tensor.device)
        img = img_tensor.mul(std[0]) + mean[0]
        img = img.transpose(0, 1).transpose(1, 2)
        img = img.numpy() * 255

        if img.shape[2] == 3:
            img = Image.fromarray(img.astype('uint8')).convert('RGB')
        elif img.shape[2] == 1:
            img = Image.fromarray(img.astype('uint8').squeeze())
        return img


print(os.getcwd())

norm_mean = [0.485, 0.456, 0.406]
norm_std = [0.229, 0.224, 0.225]
train_transform = transforms.Compose((
    transforms.Resize((225, 225)),
    # 中心裁剪 
    transforms.CenterCrop((100, 100)),
    transforms.ToTensor(),
    transforms.Normalize(norm_mean, norm_std)))

train_dir = './data/split_data/train'
dataset = rmb_dataset.RMBDataset(train_dir, train_transform)
train_loader = DataLoader(dataset, batch_size=4, shuffle=False)

img, label = next(iter(train_loader))
img = img[0, ...]
img = transform_invert(img, train_transform)
plt.imshow(img)
plt.show()
plt.pause(0.5)
plt.close()
