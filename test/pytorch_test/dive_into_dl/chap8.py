from d2l import torch as d2l
import torch
from torch import nn

# ======================== data ======================
T = 1000
time = torch.arange(1, T + 1, dtype=torch.float32)
x = torch.sin(0.01 * time) + torch.normal(0, 0.2, (T,))
d2l.plot(time, [x], "time", 'x', xlim=[1, 1000], figsize=(6, 3))

tau = 4
features = torch.zeros(T - tau, tau)
for i in range(tau):
    features[:, i] = x[i:T - tau + i]
labels=x[tau:].reshape(-1,1)

batch_size,n_train=16,600


