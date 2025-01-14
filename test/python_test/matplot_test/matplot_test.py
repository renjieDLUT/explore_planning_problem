'''
Author: renjie renjie_dlut2016@163.com
Date: 2024-05-09 14:26:51
LastEditors: renjie renjie_dlut2016@163.com
LastEditTime: 2024-05-09 14:28:05
FilePath: /explore_planning_problem/test/python_test/matplot_test/matplot_test.py
Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
'''
import matplotlib.pyplot as plt  

  

# 创建一个figure和它的网格  

fig = plt.figure(figsize=(10, 5))  

  

# 在整个figure上创建一个2x1的网格，但是只使用第一个位置（1, 1）  

ax1 = fig.add_subplot(2, 1, 1)  

  

# 在ax1内部（实际上不是，但我们可以通过调整位置来模拟）创建一个2x1的子网格  

# 注意：这不是真正的嵌套subplot，而是两个独立的subplot  

ax1a = fig.add_subplot(2, 2, 2)  # 使用整个网格的(2, 2)位置来定义第一个子subplot  

ax1b = fig.add_subplot(2, 2, 4, sharex=ax1a)  # 使用整个网格的(2, 4)位置来定义第二个子subplot，并共享x轴  

  

# 你可以通过调整subplot_spec参数或者使用GridSpec来更精细地控制位置  

# 例如，使用GridSpec  

gs = fig.add_gridspec(2, 2)  

ax2 = fig.add_subplot(gs[0, :])  # 使用整个第一行来定义第二个主要subplot  

ax2a = fig.add_subplot(gs[1, 0])  # 使用第二行的第一列来定义ax2内部的子subplot  

ax2b = fig.add_subplot(gs[1, 1])  # 使用第二行的第二列来定义ax2内部的另一个子subplot  

  

# 现在，你可以在每个subplot上绘制你的数据  

ax1.plot([1, 2, 3], [1, 2, 3])  

ax1a.plot([1, 2, 3], [1, 4, 9])  

ax1b.plot([1, 2, 3], [2, 5, 12])  

ax2.plot([1, 2, 3], [3, 2, 1])  

ax2a.plot([1, 2, 3], [3, 5, 7])  

ax2b.plot([1, 2, 3], [2, 3, 5])  

  

plt.tight_layout()  # 调整子图参数，使之填充整个图像区域  

plt.show()
pause()