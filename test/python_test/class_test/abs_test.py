'''
Author: renjie renjie_dlut2016@163.com
Date: 2024-01-10 15:05:49
LastEditors: renjie renjie_dlut2016@163.com
LastEditTime: 2024-01-30 14:23:51
FilePath: /explore_planning_problem/test/python_test/class_test/abs_test.py
Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
'''
from abc import ABC, abstractmethod

def fertility():
    print("can Fertility!")

def make_moneny():
    print("can make money!")

class Person(ABC):
    def __init__(self, name: str, age: int):
        self.name = name
        self.age = age

    @abstractmethod
    def function(self):
        pass

class Human(Person):
    def function(self):
        return fertility


limei = Human("hxj", 28)

limei.function()()

print(isinstance(limei,Person))
print(isinstance(limei,Human))