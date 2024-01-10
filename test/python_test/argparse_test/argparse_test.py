# 导入库
import argparse

# 1. 定义命令行解析器对象
parser = argparse.ArgumentParser(description='Demo of argparse')

# 2. 添加命令行参数
parser.add_argument('--epochs', type=int, default=30)
parser.add_argument('--batch', type=int, default=4)
parser.add_argument('--print', action='store_true')
parser.add_argument('--names', nargs='+')


# 3. 从命令行中结构化解析参数
args = parser.parse_args()
print(args)
epochs = args.epochs
batch = args.batch
print('show {} {}  {} {}'.format(epochs, batch, args.print,args.names))
