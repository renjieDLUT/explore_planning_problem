# import math
# import torch
# from torch.nn import functional as F
# from d2l import torch as d2l
#
# batch_size, num_step = 32, 35
# train_iter, vocab = d2l.load_data_time_machine(batch_size, num_step)
# data = F.one_hot(torch.tensor([0, 2]), 28)
#
# X = torch.arange(10).reshape((2, 5))
# print(F.one_hot(X.T, 28).shape)
#
#
# def get_params(vocab_size, num_hiddens, device):
#     num_input = num_outputs = vocab_size
#
#     def normal(shape):
#         return torch.randn(size=shape, device=device) * 0.01
#
#     W_xh = normal((num_input, num_hiddens))
#     W_hh = normal((num_hiddens, num_hiddens))
#     b_h = torch.zeros(num_hiddens, device=device)
#
#     W_hq = normal((num_hiddens, num_outputs))
#     b_q = torch.zeros(num_outputs, device=device)
#
#     params = [W_xh, W_hh, b_h, W_hq, b_q]
#     for param in params:
#         param.requires_grad_(True)
#     return params
#
#
# def init_rnn_state(batch_size, num_hiddens, device):
#     return torch.zeros(batch_size, num_hiddens, device=device)
#
#
# def rnn(inputs, state, params):
#     W_xh, W_hh, b_h, W_hq, b_q = params
#     H = state
#     outputs = []
#
#     for X in inputs:
#         H = torch.tanh(torch.mm(X, W_xh) + torch.mm(H, W_hh) + b_h)
#         Y = torch.mm(H, W_hq) + b_q
#         outputs.append(Y)
#     return torch.cat(outputs, dim=0), H
#
#
# class RNNModelScratch:
#     def __init__(self, vocab_size, num_hiddens, device, get_params, init_state, forward_fn):
#         self.vocab_size, self.num_hiddens = vocab_size, num_hiddens
#         self.params = get_params(vocab_size, num_hiddens, device)
#         self.init_state, self.forward_fn = init_state, forward_fn
#
#     def __call__(self, X, state):
#         X = F.one_hot(X.T, self.vocab_size).type(torch.float32)
#         return self.forward_fn(X, state, self.params)
#
#     def begin_state(self, batch_size, device):
#         return self.init_state(batch_size, self.num_hiddens, device)
#
#
# num_hiddens = 512
# net = RNNModelScratch(len(vocab), num_hiddens, d2l.try_gpu(), get_params, init_rnn_state, rnn)
# state = net.begin_state(X.shape[0], d2l.try_gpu())
# Y, new_state = net(X.to(d2l.try_gpu()), state)
#
#
# def predict(prefix, num_preds, net, vocab, device):
#     state = net.begin_state(batch_size=1, device=device)
#     outputs = [vocab[prefix[0]]]
#     get_input = lambda: torch.tensor([outputs[-1]], device=device).reshape((1, 1))
#     for y in prefix[1:]:
#         _, state = net(get_input(), state)
#         outputs.append(vocab[y])
#     for _ in range(num_preds):
#         y,state=net(get_input(),state)
#         outputs.append(int(y.argmax(dim=1).reshape(1)))
#
#     return ''.join([vocab.idx_to_token[i] for i in outputs])
#
# res=predict("time traveller ",10,net,vocab,d2l.try_gpu())
# print(res)
#
# def grad_clipping()
import torch.nn

#  ============================= use api ======================
import torch
import d2l.torch

batch_size,num_steps=32,35
train_iter,vocab=d2l.torch.load_data_time_machine(batch_size=batch_size,num_steps=num_steps)
num_hiddens=256
run_layer=torch.nn.RNN(len(vocab),num_hiddens)

state=torch.zeros((1,batch_size,num_hiddens))

x=torch.arange(-8.,8.,0.1,requires_grad=True)
y=torch.relu(x)
d2l.torch.plot(x.detach(),y.detach(),'x','relu(x)',figsize=(5,2.5))
d2l.torch.plt.show()
