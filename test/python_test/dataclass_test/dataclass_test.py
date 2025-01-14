'''
Author: renjie renjie_dlut2016@163.com
Date: 2024-02-06 19:24:05
LastEditors: renjie renjie_dlut2016@163.com
LastEditTime: 2024-02-06 19:34:57
FilePath: /explore_planning_problem/test/python_test/dataclass_test/dataclass_test.py
Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
'''
from dataclasses import dataclass
import dacite
from typing import Union


@dataclass
class Base1Config:
    age: int
    name: str


@dataclass
class Base2Config:
    school: str


@dataclass
class StudentConfig:
    base_config: Union[Base1Config, Base2Config]
    id: int
    grade: int


data = {"base_config": {"school":"hhdx"}, "id": 12, "grade": 9}


config = dacite.from_dict(StudentConfig, data)
print(config)
