- dir(obj): 内置函数,用于返回一个列表,其中包含给定对象的所有属性和方法.
- dir( ): 返回一个包含python解释器中所有内置函数和模块的列表
- *.pyi: 存根文件可以简单的理解为一个函数参数类型的静态类型检查器,在编写代码的时候就给出提示
- if推导式
```python
x = 0
result = "yes" if x == 1 else "no"
```
- 列表推导式
```python
x = [x for x in range(10)]

x = [x for x in range(10) if x > 5]
```

- 字典推导式
```python
movies={"the shawshank redemption":9.3,"the godfather":9.2,"the dark knight":9.0}
movies={movie:rating for movie,rating  in movies.items() if rating>=9.2}
```
- 生成器表达式
```python
# 生成器表达式
numbers = [1, 2, 3, 4, 5, 6]
even_numbers = (number for number in numbers if number % 2 == 0)
```

- with :一种上下文管理协议,包含方法__enter__和__exit__,支持该协议需要实现这两个方法
```python
class MyWork:
    def __enter__(self):
        print("welcome to my world!")
        
    def __exit__(self):
        print("see you again")

with MyWork() as work:
    print("...")
```

- 类中以 **__**  开头的变量为私有变量; 两端都有 **__** 是内置方法

- **装饰器decorator**:一个可调用的(函数、方法和类),它获得一个函数对象func_in作为输入,并返回另一个函数对象func_out.用于扩展函数、方法或类的行为
## 内置函数
- eval():将字符串str当成  有效的表达式来求值并返回计算结果
```python
str = "3+2"
result = eval(str)
```

- hasattr(): 判断对象是否有属性
```python
hasattr(int,'__name__')
```

- filter(function, iterable): 过滤序列,过滤掉不满足条件的元素.返回迭代器对象.
```python
def is_odd(n: int):
    return n % 2 == 0


odds_generator = filter(is_odd, range(10))
odds = list(odds_generator)
```

## 类class
- 实例方法
```python
class Foo:
    def __int__(self):
        pass
    
    def normal_func(self):
        pass
```
- 类方法
```python
class Foo:
    def __init__(self):
        pass
    
    @classmethod
    def cls_func(cls):
        pass
```
- 静态方法: 和c++不一样,不能访问类变量
```python
class Foo:
    def __init__(self):
        pass

    @staticmethod
    def static_func(self):
        pass
```
