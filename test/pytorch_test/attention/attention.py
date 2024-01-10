import torch
from torch import nn as nn


class Self_Attention(nn.Module):
    def __init__(self, dim, dk, dv):
        super(Self_Attention, self).__init__()
        self.q = nn.Linear(dim, dk)
        self.k = nn.Linear(dim, dk)
        self.v = nn.Linear(dim, dv)
        self.scale = dk ** -0.5

    def forward(self, X):
        q = self.q(X)
        k: torch.Tensor = self.k(X)
        v = self.v(X)

        attn = torch.matmul(q, k.transpose(-1, -2)) * self.scale
        attn = attn.softmax(dim=-1)
        x = torch.matmul(attn, v)
        return x


if __name__ == "__main__":
    att = Self_Attention(dim=2, dk=2, dv=3)
    x = torch.rand((1, 4, 2))
    y = att(x)
    print(y.shape)

