from ast import Module
import torch.nn as nn
import torch.nn.functional as F
import torch.optim


class LeNet(nn.Module):
    def __init__(self) -> None:
        super().__init__()
        self.conv1 = nn.Conv2d(3, 6, 5)
        self.conv2 = nn.Conv2d(6, 16, 5)
        self.fc1 = nn.Linear(16*5*5, 120)
        self.fc2 = nn.Linear(120, 84)
        self.fc3 = nn.Linear(84, 10)
        nn.ReLU()

    def forward(self, x):
        h1 = F.relu(self.conv1(x))
        h1 = F.max_pool2d(h1, 2)

        h2 = F.relu(self.conv2(h1))
        h2 = F.max_pool2d(h2, 2)

        flatten = h2.view(h2.size(0), -1)
        f1 = F.relu(self.fc1(flatten))
        f2 = F.relu(self.fc2(f1))
        f3 = self.fc3(f2)
        return f3

net = LeNet()
# print(net._modules)
for module in net.named_modules():
    print(module)


print(optimizer.state_dict())