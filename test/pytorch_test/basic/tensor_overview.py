# -*- coding:utf-8 -*-
"""
张量的创建
张量的操作(拼接,切分,索引和变换)
张量的数学运算
"""
import torch
import numpy as np

# =============================根据数据直接创建===============================
arr = np.ones((3, 3))

t = torch.tensor(arr, dtype=torch.float, device='cpu')

list_data = [1, 2, 3]
t = torch.tensor(list_data)
tuple_data = (1, 2, 3, 4)
t = torch.tensor(tuple_data)

# =============================from_numpy 创建(共享内存)===============================
arr = np.ones((3, 3))
t = torch.from_numpy(arr)
arr[1, 2] = 10.

# =============================依据数值 创建===============================
# zeros, zeros_like
# ones, ones_like
# full, full_like
# arange  等差数列
# linspace   均分数列
# logspace   对数均分数列
# eye

t = torch.zeros([2, 3])
t2 = torch.zeros_like(t)
t = torch.ones([2, 3])
t2 = torch.ones_like(t)
t3 = t2.add(t)
t = t + t2
t = torch.full([2, 3], 11.1)
t2 = torch.full_like(t, 3.3)
t = torch.arange(0, 10, 3)

t = torch.linspace(0, 10, 3)

t = torch.logspace(0, 10, 3)

t = torch.eye(3, 4)

# =============================依据概率分布 创建===============================
# normal

mean1, std1 = 0.0, 1.0
mean2, std2 = torch.tensor([0.0, 1.0]), 1.0
mean3, std3 = 1.0, torch.tensor([0.0, 1.0])
mean4, std4 = torch.tensor([0.0, 1.0]), torch.tensor([0.0, 1.0])

t1 = torch.normal(mean1, std1, (4, 2))
t2 = torch.normal(mean2, std2)
t3 = torch.normal(mean3, std3)
t4 = torch.normal(mean4, std4)

# randn , randn_like  标准正态分布
t = torch.randn([2, 3])
t = torch.randn_like(torch.ones(3, 3))

# rand , rand_like
t = torch.rand([2, 3])
t = torch.rand_like(torch.ones(3, 3))

# randint,randint_like
t = torch.randint(-10, 10, (3, 3))
t = torch.randint_like(torch.ones(2, 3), -10, 10)

# randperm
t = torch.randperm(10)

# bernoulli 两点分布
t = torch.bernoulli(torch.full((2, 3), 0.25))

# =============================张量操作(拼接,切分,张量索引,变换)===============================
t = torch.ones(2, 3)
t = torch.cat([t, t], dim=0)
t = torch.cat([t, t, t], dim=1)

t = torch.stack([t, t], dim=0)

ts = torch.chunk(t, 2, 0)

ts = torch.split(t, 3, dim=1)

t = torch.index_select(t, dim=2, index=torch.tensor([1, 2]))

t = torch.randint(0, 9, (3, 3))
mask = t.le(5)
t = torch.masked_select(t, mask)

t = torch.rand((3, 2))
t = t.reshape(2, 3)

t = torch.rand((2, 3, 4))
t = t.transpose(0, 2)

t = torch.rand((1, 2, 3))
t = t.squeeze()

t = t.unsqueeze(dim=1)

# =============================张量数学运算===============================
t1 = torch.randn(3, 3)
t2 = torch.randn(3, 3)
torch.add(t1, t2)

# =============================计算图===============================
w = torch.tensor([1.], requires_grad=True)
x = torch.tensor([1.], requires_grad=True)

a = torch.add(w, x)
b = torch.add(w, 1)
y = torch.mul(a, b)

y.backward()
print(y.requires_grad)
print(w.grad, y.grad_fn)

# ============================= other ===============================
t = torch.tensor([1, 2, 3])
print(t.numel(), t.shape, t.size())
t = t.unsqueeze(dim=0)
print(t, t.shape)
t = t.squeeze()
print(t, t.shape)
t=t.view([3,1])
print(t,t.shape)

torch.autograd.Function