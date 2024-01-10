from torch.nn import Module, Sequential
import torch.nn as nn
import torch


class LeNetSequential(Module):
    def __init__(self, classes: int):
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
            nn.Linear(84, classes),
        )

    def forward(self, x: torch.Tensor):
        x: torch.Tensor = self.features(x)
        x = x.flatten(1)
        x = self.classifier(x)
        return x
