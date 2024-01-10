# ========================= 基础数据类型 ============================
from typing import List
a = 3
string = "hello"
t = (3, 4, 5)
l = [1, 2, 3, 4]
s = (1, 2, 3)
d = {"name": "hello_python", "age": 18}

class_names = [
    "小汽车", "汽车", "货车", "工程车", "巴士", "摩托车", "自行车", "三轮车", "骑车人", "骑行的人", "人",
    "行人", "其它", "残影", "蒙版", "其他", "拖挂", "锥桶", "防撞柱"
]

d = dict(class_names=class_names)  # 使用关键字作为参数

from addict import Dict
d=Dict(d)

print(d.class_names)
d.key=12
print(d.key)

# ========================== 类型转换 ===============================

# ========================== 命名 ===========================
_var1 = "var1"
_var2_ = "var2"
__var3 = "var3"
print(dir())


class Foo():
    global_data = 4

    def __init__(self) -> None:
        self._var1 = "Foo:var1"
        self._var2_ = "Foo:var2"
        self.__var3 = "Foo:var3"  # python解释器会更改
        pass

    def method(self) -> None:
        self.data = 3


f = Foo()
print(dir(f))
f.method()
print(dir(f))
print(f.__dict__)
print(Foo.__base__)

# ==============================  面向对象 ==============================
# ==============================  继承 ==============================
print("=============================================")


class Base:
    def __init__(self) -> None:
        self.base_data = 1
        print("[Base]:", self.__class__)
        pass

    def base_method(self):
        pass


class Drived(Base):
    def __init__(self) -> None:
        super().__init__()
        print("[Drived]:", self.__class__)

        pass

    @property
    def drived_method(self):
        Base.base_method(self)
        return self.base_data


drived1 = Drived()
print(drived1.__dict__)
print(drived1.__dir__())
print(drived1.drived_method)


# ======================= 静态类型检查 ================
print("======================= 静态类型检查 ================")
data: List[int] = [1, 2, 4]
print(data)

# ====================  自定义类型作为　字典的ｋｅｙ=============
print("===================  自定义类型作为 字典的ｋｅｙ=======") 


class Person:
    def __init__(self, name, age):
        self.name = name
        self.age = age

    def __hash__(self):
        return hash((self.name, self.age))

    def __repr__(self):
        return str(tuple((self.name, self.age)))


persons_info = dict()

persons_info[Person("renjie", 29)] = 1
persons_info[Person("huangxuejuan", 28)] = 2
print(persons_info)

data = {"name": "renjie", "age": 29}
x, y = data
print(x, y)

def fun():
    return 1,2

res=fun()
print(res,type(res))