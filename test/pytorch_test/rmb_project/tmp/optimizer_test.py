import torch
from torch import optim

x = torch.tensor([10.], requires_grad=True)
x.grad = torch.tensor([2.])

optimizer = optim.SGD([x], lr=0.01, momentum=0.1)

optimizer.step()
print(x)

optimizer.step()
print(optimizer)
print(optimizer.state_dict())
w=torch.tensor([12,73])
optimizer.add_param_group({"params": w,"lr":0.02})
print(optimizer.state_dict())
print(optimizer.param_groups[1])