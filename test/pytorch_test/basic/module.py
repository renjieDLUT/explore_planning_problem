import torch.nn as nn
import torch

linear = nn.Linear(3, 4)

param_dict = dict()

for name, param in linear.named_parameters():
    print(name, '\n', param)
    param_dict[param] = name
    print(hash(param))

for name, sub in linear.named_modules():
    print(name, "\n", sub)

x = torch.ones(1)
w = torch.ones(1, requires_grad=True)
y = torch.mul(x, w)
y_hat = y.clone()

y_hat.backward()

print(w.grad)
