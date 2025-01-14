'''
Author: renjie renjie_dlut2016@163.com
Date: 2024-02-02 14:50:44
LastEditors: renjie renjie_dlut2016@163.com
LastEditTime: 2024-02-02 14:50:47
FilePath: /explore_planning_problem/test/python_test/dtw_test/dtw_test.py
Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
'''
import numpy as np  
from fastdtw import fastdtw  
  
# 定义两个时间序列  
time_series1 = np.array([[1, 2], [3, 4], [5, 6]])  
time_series2 = np.array([[2, 3], [4, 5]])  
  
# 计算DTW距离  
distance, path = fastdtw(time_series1, time_series2)  
  
print("DTW距离:", distance)  
print("路径:", path)