'''
Author: renjie renjie_dlut2016@163.com
Date: 2024-01-29 15:53:17
LastEditors: renjie renjie_dlut2016@163.com
LastEditTime: 2024-02-02 20:23:26
FilePath: /explore_planning_problem/test/python_test/numpy_test/read_npy_test.py
Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
'''
import numpy as np
import os

PATH = "/home/renjie/renjie_ws/dataset/av/val/val/preprocess/PIT_11430"
PATH = "/home/renjie/renjie_ws/dataset/av/val/val/preprocess_vectornet/PIT_11430"
# PATH="/tmp/tmp1/preprocess_vectornet/1704886550106564352"
PATH = "/tmp/tmp/100"

files = [os.path.join(PATH, f) for f in os.listdir(PATH) if f.endswith(".npy")]
print(files)

all_data = []
for f in files:
    data = np.load(f)
    all_data.append(data)
    print(os.path.basename(f))
    print(type(data))
    print(data.dtype)
    print(data.shape)
    print(np.issubdtype(data.dtype, np.integer))
    print(np.issubdtype(data.dtype, np.floating))
    print('\n')

data = [
    {
        "x": 525608.883789062,
        "y": 3509751.04199219
    },
    {
        "x": 525608.898114873,
        "y": 3509761.04197973
    },
    {
        "x": 525608.905273438,
        "y": 3509765.79101562
    }]

print(np.array(data))
