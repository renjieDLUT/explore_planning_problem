# -*- utf-8 -*-
'''
线性回归
'''

import torch
import matplotlib.pyplot as plt

lr = 0.05
# 创建数据
x = torch.randint(-10, 10, (10,)).to(torch.float)
y = 5.0 * x + 10.0 + torch.randn((10,))  # broadcast

# 构建线性回归参数
w = torch.randn((1), requires_grad=True)
b = torch.randn((1), requires_grad=True)

for iteration in range(1000):
    wx = torch.mul(w, x)
    y_hat = wx + b

    loss = (0.5 * (y - y_hat) ** 2).mean()
    loss.backward()

    w.data.sub_(lr * w.grad)  # type: ignore
    b.data.sub_(lr * b.grad)  # type: ignore

    w.grad.zero_()
    b.grad.zero_()

    if iteration % 20 == 0:
        plt.clf()
        plt.scatter(x.data.numpy(), y.data.numpy())
        plt.plot(x.data.numpy(), y_hat.data.numpy(), 'r-', lw=5)
        plt.text(2, 20, 'Loss=%.4f' % loss.data.numpy(), fontdict={'size': 20, 'color': 'red'})
        plt.xlim(-10, 10)
        plt.ylim(-50, 50)
        plt.title("Iteration: {}\nw: {} b: {}".format(iteration, w.data.numpy(), b.data.numpy()))
        plt.pause(1.5)

        if loss.data.numpy() < 1:
            break
