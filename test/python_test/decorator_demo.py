from typing import Any
import time


def decorate_foo(f):
    def function():
        print("new function")
        f()

    return function


@decorate_foo
def foo():
    print("foo function")
    return


print(foo.__name__)


def decorate_timer(fun):
    def wrap_fun(*args, **kwargs):
        tic = time.time()
        fun(*args, **kwargs)
        toc = time.time()
        print(f"cost time:{toc-tic}")
    return wrap_fun


# 带参数的装饰器
def logging(level):
    def wrapper(func):
        def inner_wrapper(*args, **kwargs):
            print(f"{level}:enter function {func.__name__}")

            return func(*args, **kwargs)
        return inner_wrapper
    return wrapper


@logging("INFO")
@decorate_timer
def fun1():
    time.sleep(1.)
    return


fun1()

# 装饰器函数其实是这样一个接口约束,必须接受一个callable对象作为参数,然后返回一个callable对象.
# 只要对象重载了__call__()方法,那么这个对象就是callable


class logging(object):
    def __init__(self, func) -> None:
        self.func = func

    def __call__(self, *args: Any, **kwds: Any) -> Any:
        print(f'normal logging: enter function {self.func.__name__}')
        return self.func()


@logging
def fun2():
    print("****fun2***")


fun2()


# 带参数的类装饰器

class logging2(object):
    def __init__(self, level):
        self.level = level

    def __call__(self, func) -> Any:
        def wrapper(*args, **kwargs):
            print(f"[LOGGING2] {self.level}: enter function {func.__name__}")
            return func(*args, **kwargs)
        return wrapper


@logging2("ERROR")
def fun3():
    print("************fun3********")


fun3()


# 内置的装饰器
class foo:
    def __init__(self) -> None:
        self._x=100
        return

    @property
    def x(self):
        return self._x
    
    @x.setter
    def x(self,value):
        self._x=value
    
f=foo()

print(f.x)

f.x=200
print(f.x)