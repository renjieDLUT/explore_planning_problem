from typing import Union

variable: Union[int, str]

variable = 1
print(variable)

variable = []
print(variable)


class Foo:
    def __init__(self, name: str):
        self.name = name

    def __getattribute__(self, item: str):
        if item == "name":
            print('accessing the "name" attribute')
        return object.__getattribute__(self, item)


f = Foo("hello")
print(type(f), type(Foo))
print(f.name)
print(dir(object))

lists = [int, str, Foo, None]
for _ in lists:
    print(_)

print(id(int), id(5))
print(dir())


class Person:
    def __init__(self, name, age):
        self.name = name
        self.age = age

    @property
    def name(self):
        return self._name

    @name.setter
    def name(self, value):
        self._name = value

    @property
    def age(self):
        return self._age

    @age.setter
    def age(self, value):
        self._age = value


p = Person('dad', 12)
print(p.age)
print(dir(p))

import matplotlib.pyplot as plt
import numpy as np


def step_funtion(x1: np.ndarray):
    return np.array(x1 > 0, dtype=np.int)


def sigmoid(x1: np.ndarray):
    return 1 / (1 + np.exp(-x1))


def relu(x: np.ndarray):
    return np.maximum(0, x)


x = np.arange(-5., 5., 0.1)
y = step_funtion(x)
plt.plot(x, y)
plt.ylim(-0.1, 1.1)
z = sigmoid(x)
plt.plot(x, z)
plt.show()

x = np.array([[1, 2], [2, 3], [3, 4]])
y = np.array([1, 2])
print(x.shape, y.shape)
print(np.dot(x, y))

# ================================ matplotlib============================
import matplotlib.pyplot as plt

plt.figure(1)
plt.plot([1, 2, 3, 4], [1, 2, 3, 4])
plt.show()

figure: plt.Figure = plt.figure(1)
ax: plt.Axes = figure.add_subplot(2, 2, 1)
ax.plot([1, 2, 3, 4], [1, 1, 1, 1])
ax.set_xlabel("feature")
plt.show()


# =============================== inheritance 继承========================

class Base:
    def __init__(self, name, age):
        self.name = name
        self.age = age


class Derive(Base):
    def __int__(self, name, age):
        super(Derive, self).__init__("renjie", 29)
        self.address = "beijing"


obj = Derive("hxj", 28)

print(type(obj))

print(isinstance(obj, Derive), isinstance(obj, Base))


# ============================= with ===============================

class MyWork:
    def __enter__(self):
        print("welcome to my world!")

    def __exit__(self, exc_type, exc_val, exc_tb):
        print("see you again")


with MyWork() as work:
    print("...")

# ============================= id ===============================
data = [1, 2, 3, 4]
print(id(data), id(data[0]), id(data[1]), id(data[2]))
x = data[0:4:2]
print(x)


# ============================= class ===============================
class Foo:
    name = ""

    def __int__(self):
        self.age = 18
        self.__secret = "you guess!"

    def add_address(self, age):
        self.address = "beijing"


obj1 = Foo()
obj2 = Foo()
obj2.name2 = "hello"
Foo.name = "world"
print(obj1.name, obj2.name, Foo.name)
print(dir(obj2))


# ============================= __dir__ ===============================
class Foo:
    def __dir__(self):
        return []


obj = Foo()
print(dir(obj))

string = "hello {}"
string = string.format("world")
print(string)
