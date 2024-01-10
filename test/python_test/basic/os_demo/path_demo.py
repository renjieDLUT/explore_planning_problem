import os

print(os.path.basename("/home/renjie/file.txt"))

res=os.path.splitext("/home/renjie/file.txt")
print(res)

for root,dirs,files in os.walk('./test/python_test'):
    print('*'*30)
    print(root)
    print(dirs)
    print(files)

paths=os.listdir('./test/python_test')
print(paths)
import sys
print(os.getcwd())