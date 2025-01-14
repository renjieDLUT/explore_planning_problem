
import numpy as np
from scipy.spatial.transform import Rotation as R
import math


def rpy_to_quaternion(roll, pitch, yaw):

    # 将欧拉角从度转换为弧度
    roll = np.radians(roll)
    pitch = np.radians(pitch)
    yaw = np.radians(yaw)

    # 使用欧拉角公式计算四元素
    # 注意：这里使用的顺序是 Z-Y-X，也就是 yaw-pitch-roll
    # 根据需要，您可以更改顺序以适应不同的旋转约定
    cy = np.cos(yaw * 0.5)
    sy = np.sin(yaw * 0.5)
    cr = np.cos(roll * 0.5)
    sr = np.sin(roll * 0.5)
    cp = np.cos(pitch * 0.5)
    sp = np.sin(pitch * 0.5)

    # 使用这些值来计算四元素
    w = cy * cr * cp + sy * sr * sp
    x = cy * sr * cp - sy * cr * sp
    y = cy * cr * sp + sy * sr * cp
    z = sy * cr * cp - cy * sr * sp

    # 返回四元素，通常是(w, x, y, z)
    return np.array([x, y, z, w])


def quaternion_to_euler_angles(quaternion):
    # 将四元素转换为旋转矩阵
    rotation_matrix = R.from_quat(quaternion).as_matrix()

    # 使用scipy的Rotation模块将旋转矩阵转换为欧拉角
    euler_angles = R.from_matrix(rotation_matrix).as_euler('xyz', degrees=True)

    return euler_angles


# 示例四元素 (x, y, z, w)
# quaternion = [0.016590540978116377, 0.012968083311103572, -0.99256254167039326, -0.1199007240933047]

quaternion = rpy_to_quaternion(0., 0., 90)
print(quaternion)

# 调用函数
euler_angles = quaternion_to_euler_angles(quaternion)

print("欧拉角（以度为单位）:", euler_angles)
