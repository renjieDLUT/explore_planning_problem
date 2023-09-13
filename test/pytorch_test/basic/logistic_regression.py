
import torch
import matplotlib.pyplot as plt
import numpy as np

# ========================生成数据==============================
sample_nums = 100
dimension = 2
mean_value = 1.7
bias = 0.
x0 = torch.normal(mean_value * torch.ones(sample_nums, 2), 1) + bias
y0 = torch.zeros(sample_nums)

x1 = torch.normal(-mean_value * torch.ones(sample_nums, 2), 1) + bias
y1 = torch.ones(sample_nums)

x = torch.cat([x0, x1], 0)
y = torch.cat([y0, y1], 0)


# ========================选择模型==============================


class LR(torch.nn.Module):
    def __init__(self, *args, **kwargs) -> None:
        super().__init__(*args, **kwargs)
        self.features = torch.nn.Linear(2, 1)
        self.sigmoid = torch.nn.Sigmoid()

    def forward(self, x):
        x = self.features(x)
        x = self.sigmoid(x)
        return x


net = LR()

# ========================选择损失函数==============================
loss_fn = torch.nn.BCELoss()

# ========================选择优化器==============================
lr = 0.01
optimizer = torch.optim.SGD(net.parameters(), lr=lr, momentum=0.9)
lr_scheduler = torch.optim.lr_scheduler.StepLR(optimizer, 50, 0.1)

for iteration in range(1000):
    y_hat = net(x)
    loss = loss_fn(y_hat.squeeze(), y)
    loss.backward()
    optimizer.step()
    optimizer.zero_grad()
    # 绘图
    if iteration % 20 == 0:
        plt.clf()
        lr_scheduler.step()

        mask = y_hat.ge(0.5).float().squeeze()  # 以0.5为阈值进行分类
        correct = (mask == y).sum()  # 计算正确预测的样本个数
        acc = correct.item() / y.size(0)  # 计算分类准确率

        plt.scatter(x0.data.numpy()[:, 0], x0.data.numpy()[:, 1], c='r', label='class 0')
        plt.scatter(x1.data.numpy()[:, 0], x1.data.numpy()[:, 1], c='b', label='class 1')

        w0, w1 = net.features.weight[0]
        w0, w1 = float(w0.item()), float(w1.item())
        plot_b = float(net.features.bias[0].item())
        plot_x = np.arange(-6, 6, 0.1)
        plot_y = (-w0 * plot_x - plot_b) / w1

        plt.xlim(-5, 7)
        plt.ylim(-7, 7)
        plt.plot(plot_x, plot_y)

        plt.text(-5, 5, 'Loss=%.4f' % loss.data.numpy(), fontdict={'size': 20, 'color': 'red'})
        plt.title("Iteration: {}\nw0:{:.2f} w1:{:.2f} b: {:.2f} accuracy:{:.2%}".format(iteration, w0, w1, plot_b, acc))
        plt.legend()

        # plt.show()
        plt.pause(0.5)

        if acc > 0.99:
            break
