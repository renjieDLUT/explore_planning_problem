import torch
import matplotlib.pyplot as plt
from d2l import torch as d2l

x, y = torch.meshgrid(torch.linspace(-1., 1., 101), torch.linspace(-1., 1., 101))

z = x ** 2 - y ** 2

ax = plt.figure().add_subplot(111, projection='3d')
ax.plot_wireframe(x, y, z)
ax.plot([0], [0], [0], 'rx')
plt.show()

def show_trace(results, f):
    n = max(abs(min(results)), max(results))
    X = torch.arange(-n, n, 0.01)
    d2l.set_figsize()
    d2l.plot([X, results], [[f(x) for x in X], [f(result) for result in results]], 'x', 'f(x)', fmts=['-', '-o'])


import numpy as np

c = torch.tensor(0.15 * np.pi)


def f(x):
    return x * torch.cos(c * x)


def f_grad(x):
    return torch.cos(c * x) - x * c * torch.sin(c * x)


def f_hession(x):
    return -2 * c * torch.sin(c * x) - x * c * torch.cos(c * x) * c


def newton(eta=1.):
    x = 10.0
    results = [x]
    for i in range(10):
        ｘ -= eta * f_grad(x) / f_hession(x)
        results.append(x.item())
    return results


show_trace(newton(),f)
plt.show()
torch.nn.Conv3d()