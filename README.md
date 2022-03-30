# explore_planning_problem
探索并整理自动驾驶及其他领域的决策规划问题

@[TOC]（目录）

## 1. 自动驾驶领域

### 学习路线

1. Frenet坐标系与笛卡尔坐标系之间转换关系;

   [参考博客](https://blog.csdn.net/qq_36458461/article/details/111935614)

   [参考论文](Optimal trajectory generation for dynamic street scenarios in a Frenét )

   [参考代码](https://github.com/ApolloAuto/apollo/blob/master/modules/planning/common/path/frenet_frame_path.cpp)

2. 5次多项式，3次样条，5次样条曲线：

   理解插值与拟合的区别：

   lattice规划算法：横向规划是5次多项式，纵向规划是（4次或则5次）；

   DP路径规划：采用的是3次样条曲线；

   曲线光滑：    螺旋线，2维的5次样条曲线；

   QP路径规划：piecewise_jerk_path(分段jerk路径)，本质就是3次样条曲线

   QP速度规划：piecewise_jerk_speed(分段jerk速度)，本质是3次样条曲线

   [三次多项式](https://github.com/ApolloAuto/apollo/blob/master/modules/planning/math/curve1d/cubic_polynomial_curve1d.h)

   [四次多项式](https://github.com/ApolloAuto/apollo/blob/master/modules/planning/math/curve1d/quartic_polynomial_curve1d.h)

   [五次多项式](https://github.com/ApolloAuto/apollo/blob/master/modules/planning/math/curve1d/quintic_polynomial_curve1d.h)

   [三次样条插值(知乎)](https://zhuanlan.zhihu.com/p/62860859)

   [piecewise_jerk(分段加加速度曲线，本质就是三次样条曲线)](https://github.com/ApolloAuto/apollo/blob/master/modules/planning/common/trajectory1d/piecewise_trajectory1d.h)

   

3. 静态障碍物映射到SL 图中：

4. 动态障碍物映射到ST图中：

5. lattice规划方法：

6. 什么是优化问题：

7. 构建参考线平滑优化问题：

8. 构建路径规划优化问题：

9. 熟悉A*算法：

10. 什么是动态规划问题：

11. 采用动态规划解决速度规划问题：

12. 构建速度规划优化问题：

13. 熟悉dubins、reed-shepp曲线：
