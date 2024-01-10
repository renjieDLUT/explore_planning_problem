import argparse

parser=argparse.ArgumentParser(description="Demo of argparse")

# 位置参数
parser.add_argument("first",help="first argument")
parser.add_argument('--epochs',type=int,default=30)

# 可选参数
parser.add_argument('--batch',type=int,default=4)

args=parser.parse_args()
print(args)