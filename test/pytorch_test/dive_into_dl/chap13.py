from d2l import torch as d2l
import torchvision

# cifar10 = torchvision.datasets.CIFAR10(root="data/cifar10", train=True)
#
# d2l.show_images([cifar10[i][0] for i in range(32)],4,8,scale=0.8)
# d2l.plt.show()
#
# data_dir=d2l.download_extract('hotdog')
# print(data_dir)
#
# batch_size, edge_size=32,256
#
# train_iter=d2l.load_data_bananas(batch_size)
# batch=next(iter(train_iter))
#
# imgs=(batch[0][0:10].permute(0,2,3,1))/255ll
# axes=d2l.show_images(imgs,2,5,scale=2)
# for ax,label in zip(axes,batch[1][0:10]):
#     d2l.show_bboxes(ax,[label[0][1:5]*edge_size],colors=["w"])
# d2l.plt.show()

voc_dir=d2l.download_extract('voc2012','Vocdevkit/VOC2012')