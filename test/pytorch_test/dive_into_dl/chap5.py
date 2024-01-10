import time

import torch
import torch.nn as nn


class MySequential(nn.Module):
    def __init__(self, *args):
        super().__init__()
        for idx, module in enumerate(args):
            self._modules[str(idx)] = module

    def forward(self, x):
        for block in self._modules.values():
            x = block(x)
        return x


net = nn.Sequential(nn.Linear(2, 2), nn.Conv2d(20, 100, 3), nn.Linear(3, 3))

print(*[(name, param.shape) for name, param in net[0].named_parameters()])
print(*[(name, param.shape) for name, param in net.named_parameters()])


def init_normal(m):
    if type(m) == nn.Linear:
        nn.init.normal_(m.weight, mean=0, std=0.01)
        nn.init.zeros_(m.bias)


net.apply(init_normal)

print(net[0].bias)

a = torch.randn(10000, 10000)
b = torch.rand(10000, 10000)
tic = time.time()
c = torch.mm(a, b)
toc = time.time()
print("cost time(CPU):", toc - tic)

a = torch.randn(10000, 10000, device="cuda")
b = torch.rand(10000, 10000, device="cuda")
print(a.device)
tic = time.time()
c = torch.mm(a, b)
toc = time.time()
print("cost time(GPU):", toc - tic)

x=torch.ones(6,9).unsqueeze(dim=0)
conv=nn.Conv2d(1,2,3,1,1)
y=conv(x)
print(y.shape,conv.weight.shape)

