import torch
from torch.nn import Module, Sequential, ModuleList, ModuleDict
from torchvision import models
from torch import nn
from matplotlib import pyplot as plt
from PIL import Image


class LeNetSequential(Module):
    def __init__(self):
        super(LeNetSequential, self).__init__()
        self.features = Sequential(
            nn.Conv2d(3, 6, 5),
            nn.ReLU(),
            nn.MaxPool2d(2, 2),
            nn.Conv2d(6, 16, 5),
            nn.ReLU(),
            nn.MaxPool2d(2, 2)
        )
        self.classifier = Sequential(
            nn.Linear(16 * 5 * 5, 120),
            nn.ReLU(),
            nn.Linear(120, 84),
            nn.ReLU(),
            nn.Linear(84, 10),
            nn.Softmax(dim=1)
        )

    def forward(self, x: torch.Tensor):
        x: torch.Tensor = self.features(x)
        x = x.flatten(1)
        x = self.classifier(x)
        return x


class MyModuleList(Module):
    def __init__(self):
        super(MyModuleList, self).__init__()
        self.linears = ModuleList([nn.Linear(10, 10) for i in range(10)])

    def forward(self, x):
        for layer in self.linears:
            x = layer(x)
        return x


class MyModuleDict(Module):
    def __init__(self):
        super(MyModuleDict, self).__init__()
        self.module_dict = ModuleDict({"conv1": nn.Conv2d(3, 16, 5),
                                       "conv2": nn.Conv2d(16, 6, 5)})

    def forward(self, x, layer_name):
        x = self.module_dict[layer_name](x)
        return x


if __name__ == "__main__":
    net = LeNetSequential()
    input = torch.randint(0, 255, (3, 32, 32))
    input.unsqueeze_(dim=0)
    input = input.to(dtype=torch.float)
    y_hat = net(input)
    print(y_hat)
    for param in net.parameters():
        print(param.numel())

    net = MyModuleList()
    input = torch.randn(1, 10)
    output = net(input)
    print(output)

    net = MyModuleDict()
    input = torch.randn(3, 100, 100)
    input.unsqueeze_(dim=0)
    output = net(input, 'conv1')
    print(output.shape, output)
