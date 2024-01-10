import torch.nn
from torch.nn import Module, ModuleList


class MLP(Module):
    def __init__(self, neural_num, layer_num):
        super(MLP, self).__init__()
        self.linears = ModuleList([torch.nn.Linear(neural_num, neural_num) for i in range(layer_num)])

    def forward(self, x: torch.Tensor):
        for i, linear in enumerate(self.linears):
            x = linear(x)
            x=torch.relu(x)
            print("layer:{}, std:{}".format(i, x.std()))
            if torch.isnan(x.std()):
                break
        return x

    def initialize(self):
        for linear in self.linears:
            torch.nn.init.normal_(linear.weight.data)
            torch.nn.init.zeros_(linear.bias.data)
            torch.nn.init.kaiming_normal_(linear.weight.data)


if __name__ == "__main__":
    neural_num = 256
    layer_num = 100
    net = MLP(neural_num, layer_num)
    net.initialize()
    x = torch.randn(neural_num)
    x.unsqueeze_(dim=0)
    y = net(x)
