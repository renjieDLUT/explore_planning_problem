from torch import nn
import torch
import numpy as np

data = torch.tensor([[1, 2], [1, 3], [1, 4]])
data = data.to(dtype=torch.float)
label = np.random.choice([0, 1], 3, p=[0.5, 0.5])
label = torch.tensor(label)
label = torch.tensor([0, 1, 1])
y = torch.rand(3, 2)

loss_fn = nn.CrossEntropyLoss()
loss1 = loss_fn(data, label)
loss2 = loss_fn(data, y)
print(loss1, loss2)

# fake data
inputs = torch.tensor([[1, 2], [1, 3], [1, 3]], dtype=torch.float)
target = torch.tensor([0, 1, 1], dtype=torch.long)

# ----------------------------------- 2 NLLLoss -----------------------------------
# flag = 0
flag = 1
if flag:
    weights = torch.tensor([1, 1], dtype=torch.float)

    loss_f_none_w = nn.NLLLoss(weight=weights, reduction='none')
    loss_f_sum = nn.NLLLoss(weight=weights, reduction='sum')
    loss_f_mean = nn.NLLLoss(weight=weights, reduction='mean')

    # forward
    loss_none_w = loss_f_none_w(inputs, target)
    loss_sum = loss_f_sum(inputs, target)
    loss_mean = loss_f_mean(inputs, target)

    # view
    print("\nweights: ", weights)
    print("NLL Loss", loss_none_w, loss_sum, loss_mean)
