import torch.nn as nn


class Model(nn.Module):
    def __init__(self):
        super().__init__()
        self.conv1 = nn.Conv2d(1, 20, 5)
        self.conv2 = nn.Conv2d(20, 20, 5)

    def forward(self,x):
        x=nn.functional.relu(self.conv1(x))
        return nn.functional.relu(self.conv2(x))



