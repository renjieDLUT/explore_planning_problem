## 基础
- 对象的三个特征: 身份,类型,值
- 数值,迭代类型,序列类型,映射,集合,上下文管理类型, 模块类型,class和实例,函数类型,方法类型,代码类型,object,type
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

- 命名规范:<br>
    1. 单下划线前缀 (`_var`): 近供内部使用,对于变量和方法(有点类似私有变量,但不是强制的).但会影响模块导入<br>
    2. 单下划线后缀 (`class_`): 一个变量最合适的名称已经被关键字所用
    3. 双下划线前缀 (`__var`):  会导致python解释器重写属性名称,以避免子类中的命名冲突...类似私有变量,有点强制
    4. 双下划线前缀+后缀 ( `__call__` ): 特殊用处,内置方法
    5. 单下划线 ( `_` ): 往往用于占位

- **装饰器decorator**:一个可调用的(函数、方法和类),它获得一个函数对象func_in作为输入,并返回另一个函数对象func_out.用于扩展函数、方法或类的行为

## 字符串
- f-string: python3.6引入的,字面量格式化字符串.以f开头,后跟字符串,字符串中的表达式以{}包起来,会将表达式的结果替换.
```python
name = "renjie"
f"hello {name}"
f"1+2 = {1 + 2}"
```

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

- zip([iterable,...]): 将可迭代的对象作为参数,将对象中对应的元素打包成一个元组
```python
a = [1, 2, 3]
b = ['a', 'b', 'c']
for x, y in zip(a, b):
    print(x, y)
```




## 函数

- 定义函数的时候，参数中可以使用 `/`和 `*`来限制参数类型，调用函数的时候，`/`前面只能是位置参数，`*`后面只能是关键字参数，不限制之间的参数类型

```python
def fun(param1, /, param2, *, param3):
    """
    param1: 只能是位置参数
    param2: 位置参数 与 关键字参数
    param3: 只能是关键字参数
    """
    pass
```

## 类class
1. 类
2. 类变量
3. 实例变量
4. 数据成员 : 类变量和实例变量
5. 方法重写
6. 局部变量
7. 继承<br>
    - 子类中需要调用父类的构造方法需要显示调用父类的构造方法,或则不重写父类的构造方法
    - 子类调用基类的方法时,需要加上基类的类名前缀
    - 总是首先对应类型的方法,当在派生类中找不到对应方法时,才在基类中找

#### 魔法方法
1. \_\_getstate__ 与 \_\_setstate__ 两个魔法方法分别用于Python 对象的序列化与反序列化 (常和`pickle`一起使用)
2. \_\_del__

#### python对象销毁
在python中,当没有任何引用指向一个对象时,该对象将会被自动销毁.如果我们不再使用或则删除了所有的变量名来引用该对象,那么该对象就会被标记为可以被垃圾收集器清理的候选项.

#### 抽象类
1. 概念:类是一堆对象共同内容的抽取,那么抽象类就是对一堆类共同内容的抽取
2. 特点:
    - 抽象类必须包含一个或多个抽象方法
    - 抽象类的抽象方法,在抽象类中并不实现
    - 抽象类不能被实例化
    - 抽象类的子类要想进行实例化,必须先实现抽象父类中的所有抽象方法
    - 从`abc`库中导入`ABC`,`abstractmethod`

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
- 类成员变量 与 对象成员变量
在创建实例对象时,Python会自动将类成员变量复制到每个实例变量中,因此每个实例变量有自己的对象成员变量副本
```python
class Person:
    name = 'Unknown'  # 类成员变量

    def set_name(self, name):
        self.name = name  # 修改对象成员变量

p1 = Person()
p2 = Person()

print(Person.name)    # 访问类成员变量
print(p1.name)        # 访问对象成员变量
print(p2.name)        # 访问对象成员变量

p1.set_name('Alice')   # 修改p1的对象成员变量
print(p1.name)        # 访问p1的对象成员变量
print(p2.name)        # 访问p2的对象成员变量

# 输出结果
# Unknown
# Unknown
# Unknown
# Alice
# Unknown
```

## 解释器
- GIL(global interpreter lock, 全局解释器锁):<br>
python的多线程功能在应用级别,而不是库级别.虽然支持多线程,但是一个时间只有一个线程执行Python字节码.这个限制就来源于GIL,它阻止同一时间多个线程执行字节码

## 迭代器与生成器
把一个类作为迭代器需要添加`__next__` 和`__iter__`方法
```python
class MyNumbers:
    def __iter__(self):
        self.a=1
        return self
    
    def __next__(self):
        if self.a<=20:            
            x=self.a
            self.a+=1
        else:
            raise StopIteration
        return  x

my_number=MyNumbers()
for num in my_number:
    print(num)
```

使用yield的函数称为生成器.yield是个关键字,用于定义生成器函数,可以在迭代过程中逐步产生值,而不是一次性产生所有的值<br>
生成器是一个返回迭代器的函数
```python
def countdown(n):
    while n>0:
        yield  n
        n -= 1
        
generator=countdown(5)
print(next(generator))

for n in generator:
    print(f"n:{n}")
```

```python
# 利用 生成器 来输出斐波那契数列
def fibonacci(n):
    a,b=0,1
    count=0
    while count<n:
        yield a
        a,b=b,a+b
        count+=1
    
fibonacci_generator=fibonacci(10)
for n in fibonacci_generator:
    print(n ,end=" ")

```

## 静态类型检查
提供特殊的注释,可以在代码中明确的指定变量,函数参数和函数返回值的类型.有助于提高代码的可读性和可维护性,并且可以捕捉一些类型错误
```python
from tying import List

data:List[int] =[1,2,3]
```

## 自定义类型作为字典key
确保自定义类型为 可哈希 
- 方法: 实现｀__hash__｀方法
```python
class Person:
    def __init__(self,name,age):
        self.name=name
        self.age=age
    
    def __hash__(self):
        return hash((self.name,self.age))

    def __repr__(self):
        return str(tuple((self.name,self.age)))

persons_info=dict()

persons_info[Person("renjie",29)]=1
persons_info[Person("huangxuejuan",28)]=2
print(persons_info)

```

## 枚举类型
枚举类型在Python 3.4版本以后引入，使用enum模块实现
```python
from enum import Enum

class Color(Enum):
    RED=1
    BLACK=2
    WHITE=3
```

## 工具库
```python
# 将多个可迭代对象串联在一起,返回一个迭代器
from itertools import chain

list1=[1,2,3]
list2=[4,5,6]

chained_list=list(chain(list1,list2))
print(chained_list)
```

## 库
1. **argparse** :命令行参数解析模块
2. **logging**: [https://blog.csdn.net/m0_60981735/article/details/131521374]
3. **OrderedDict**: 有序字典,遍历时按照数据添加的顺序返回
4. **json**和**pickle**:都可以实现Python对象的序列化和反序列化
5. **__future__**: 是python2和python3的桥梁
6. **enum**: 使用该模块创建枚举类型

## argparse
是python内置的用于命令项选项与参数解析的模块
**step1**: 导入argparse包
**step2**: 创建一个命令行解析器对象`ArgumentParser`对象 
**step3**: 给解析器添加命令行参数`add_argument`
**step4**: 解析命令行参数 `parse_args`
```python
# 0. 导入库
import argparse
 
# 1. 定义命令行解析器对象
parser = argparse.ArgumentParser(description='Demo of argparse')
 
# 2. 添加命令行参数
parser.add_argument('--epochs', type=int, default=30)
parser.add_argument('--batch', type=int, default=4)
 
# 3. 从命令行中结构化解析参数
args = parser.parse_args()
print(args)
epochs = args.epochs
batch = args.batch
print('show {}  {}'.format(epochs, batch))

```
**add_argument()参数详解**
1. **name or flags**:普通参数或flag参数选项参数的名称或标签.
2. **action**: 命令行遇到flags参数时的动作.有两个常见的动作,store_true:设定flag参数为true,store_false:设定flag参数为false.
3. **nargs**:应该读取的命令行参数个数,可以是具体的数字

4. **default**:不指定参数时该参数的默认值
5. **type**:命令行参数应该被转化成的数据类型
6. **required**: 是否为必选参数
7. **help**: 参数的帮助信息
8. **metavar**
9. **dest**:
## paramiko
python实现的`ssh2`协议库,可以用于连接ssh服务器并执行命令、传输文件

```python
import paramiko  

# 远程服务器的SSH信息  
host = 'remote_host'  
port = 22  
username = 'your_username'  
password = 'your_password'  

# 远程服务器上的文件路径和本地保存路径  
remote_file_path = '/path/to/remote/file.txt'  
local_file_path = '/path/to/local/file.txt' 

# 创建SSH客户端  
ssh = paramiko.SSHClient()  
ssh.set_missing_host_key_policy(paramiko.AutoAddPolicy())  # 自动添加主机密钥  
ssh.connect(host, port, username, password)  

# 打开远程文件并下载到本地  
sftp = ssh.open_sftp()  
with sftp.open(remote_file_path, 'rb+') as remote_file:  
    with open(local_file_path, 'wb+') as local_file:  
        local_file.write(remote_file.read())  

# 关闭SSH连接  
sftp.close()  
ssh.close()
```

## pandas(panel data)
当我们面对的是一个包含多种数据类型的大规模数据集时,就需要用更多的数据结构和数据操作方法来处理该数据集.
pandas中`DataFrame`和`series`利用了numpy数据作为底层结构的.
1. `Series`:是最基础的数据结构.类似于一维数组的数据结构,其中每个元素都带有一个标签.输出的第一列是`Series`的索引,起到解释、定位数据的作用(如果不指定索引,默认从0开始编号).
```python
import pandas as pd
data = range(1, 3)
pd_data = pd.Series(data)

pd_data = pd.Series(['010', '022', '021', '023'],
                    ['beijing', 'tianjing', 'shanghai', 'chognqing'])
```
2. `DataFrame`:二维异构表格数据,现实中的数据是以二维表的形式存在的,类似于excel的表格数据.在pandas中二维数据是存储在`DataFrame`数据结构中.其实就是一个`m*n`的二维数据.`DataFrame`本质上可以看作多个一维`Series`构成的二维数据.
将一个等长列表组成的字典传入`pd.DataFrame`函数中,字典的键会作为`DataFrame`的列索引,字典的值为对应每一列的数据.

```python
import pandas as pd
data={'col_1':[1,2],'col_2':[1,4]}
df=pd.DataFrame(data)
```
3. pandas的字段类型
    - float64
    - int64
    - bool
    - datatime64
    - timedelta[ns]
    - object
4. 缺失值 `numpy.NaN`
5. 数据类型转换:
实际中我们的数据通常会以列为单位,即一列的值是同一种数据类型.通过`dtypes`属性检查一列数据的字段类型,来检查数据的有效性.
```python
import pandas as pd

series_data=pd.Series(range(1,5))
series_data.dtype
```
6. 通过读取csv/Excel/parquet等文件创建`DataFrame`
## pytorch
1. Tensor:
    1. clone:  可微,梯度会传递到input
    2. 
2. Module:
    1. 实例变量:
        - `training`:`bool`类型标记是否为train模型
        - `_parameters`: 参数,一般是`requires_grad`为`True`,可直接通过name属性获取
        - `_buffers`: 可直接通过name属性获取
        - `_non_persistent_buffers_set`:  记录非持久性 buffer 集合
        - `_backward_hooks`: 
        - `_is_full_backward_hook`:
        - `_forward_hooks`:
        - `_forward_pre_hooks`:
        - `_state_dict_hooks`:
        - `_load_state_dict_pre_hooks`:
        - `_modules`: 可直接通过name属性获取

    2. 方法:
        - `register_buffer`: 注册buffer
        - `register_parameter`: 注册parameter,parameter必须是叶子节点(没有grad_fn)
        - `add_module`: 添加子模块
        - `get_submodule`: 获取子模块,可获取嵌套的子模块
        - `get_parameter`: 获取参数,可通过子模块的名字获取子模块的参数
        - `get_buffer`: 同`get_parameter`
        - `_apply(self,fn)`: 
        - `apply`: 各个子模块递归调用`fn`
        - `cuda`,`xpu`,`cpu`: 将各模块中的parameter与buffer迁移到GPU
        - `type`: 将各模块中的parameter和buffer应用type类型转换
        - `float`,`double`,`half`,`bfloat16`:
        - `to`: 转换数据类型,device等统一接口
        - `register_backward_hook`:注册backward_hook
        - `register_full_backward_hook`:
        - `_get_backward_hooks`:
        - `register_forward_pre_hook`:
        - `register_forward_hook`:
        - `_slow_forward`: 
        - `_call_impl`: 如果没有任何hook,直接调用forward函数.否则按照`_global_forward_pre_hooks`,`_forward_pre_hooks`,等等hook

        - `__call__`: 魔法方法,默认会调用`_call_impl`
        - `__setstate__`: 反序列化时使用
        - `__getattr__`: 更具name获取属性(buffer,parameter,module)
        - `__setattr__`: 设置属性
        - `__delattr__`: 删除属性
        - `_register_state_dict_hook`
        - `state_dict`: 返回模块整个状态的字典(parameter,buffer),递归遍历子模块
        - `_register_load_state_dict_pre_hook`:
        - `load_state_dict`:
        - `parameters`,`buffers`,`modules`,`children`:
        - `named_parameters`,`named_buffers`,`name_modules`,`name_children`
        - `train`: 设置为train模式
        - `eval`:
        - `requires_grad_`:
        - `zero_grad`:

3. Embedding:


## mmengine
1. BaseModule :继承至Module, 封装权值初始化
2. BaseRunner: 
    1. 实例成员
     - model: 模型
     - batch_processor: BEVformer中没使用
     - optimizer :优化器
     - logger: 日志
     - meta: 
     - 创建工作目录work_dir
     - _model_name
     - _rank, _world_size :分布式信息
     - timestamp
     - mode 
     - _hooks : List[Hook] 将
     - _epoch : 
     - _iter  : 迭代次数
     - _inner_iter: 一个epoch的迭代次数
     - _max_epoches: 初始化的时候传入 24
     - _max_iters: 与_max_epoches不能同时传入,后面通过max_epoch与传入的data_loader长度获得 `_max_iters = _max_epoches * len(data_loader)`

    2. 方法
     - train(): 抽象方法
     - val():
     - run()
     - save_checkpoint()
     - current_lr() : 获取当前学习率
     - current_momentum(): 
     - register_hook(hook, priority): 注册hook,按照优先级排序插入队列中,
     - `register_hook_from_cfg`: 根据配置文件,构建hook,并调用register_hook
     - `call_hook(self, fn_name)`: 遍历hook,获取给定的函数对象,然后调用函数
     - `get_hook_info`: 获取hook信息
     - `load_checkpoint`:
     - `resume`
     - `register_lr_hook`:
     - `register_momentum_hook`:
     - `register_optimizer_hook`:
     - `register_checkpoint_hook`:
     - `register_logger_hook`:
     - `register_timer_hook`:
     - `register_custom_hook`:
     - ``

3. EpochBasedRunner:
    1. 方法
        - `train(data_loader,**kwargs)`:
            - 设置mode为train
            - 迭代一个epoch,每次迭代调用 `run_iter`

        - `run_iter`:
            - 调用model.train_step方法

        - `run(self, data_loaders, workflow, max_epoches, **kwargs)`:
            - `data_loaders`是 列表list
            - `workflow`: 元组
            - 根据 cfg中的workflow控制流程,根据 workflow中的mode 确定是调用`train`还是`val`,`train` 


## CustomNuScenesDataset
1. 数据成员
    - `queue_length`: 时间长度,设置为3
    - `bev_size`: bev 大小
    - `overlap_test`: 

    - `load_interval`: 加载间隔
    - `use_valid_flag`: ann标注数据中有valid_flag字段,是否根据该字段进行过滤
    - `with_velocity`: 含速度信息
    - `eval_version`: 评估版本
    - `eval_detection_configs`:  评估配置,,nuscenes-kit
    - `metadata`: pkl标注文件中的metadata
    - `version`: pkl中记录的版本信息
     
    - `data_root`: 数据的根目录
    - `ann_file`: 标准文件
    - `test_mode`: 
    - `modality`: 模态信息
    - `filter_empty_gt`: bool,过滤gt为空的样本
    - `box_type_3d`: 3d包围框的类型(class类型)
    - `box_mode_3d`: 3d包围框的类别
    
    - `CLASSES`: 类变量,数据标签对应的语义标签
    - `cat2id`: dict, 根据str类别反查id
    - `data_infos`: 调用load_annotations获取的,各个样本数据
    - `pipeline`: 各个transform的集合,包括`LoadMultiViewImageFromFiles`,`PhotoMetricDistortionMultiViewImage`,`LoadAnnotations3d`,`CustomCollect3d`等
    - ``

2. 方法
    - `__getitem__`:魔法方法,根据给定的index,获取infos,如果为test_mode,那么调用`prepare_test_data`,否则调用`prepare_train_data`
    - `prepare_train_data(self, index)`:  从`queue_length`+1中选择`queue_length`帧,每帧调用`get_data_info`获取数据,调用`pipeline`进行transform操作,依据`filter_empty_gt`过滤.最后调用`union2one`合并信息
    - `get_data_info(self, index)`:返回字典,包含以下字段
        - sample_idx: sample 对应的token
        - pts_filename: lidar_path
        - sweeps: 
        - ego2global_translation
        - ego2global_rotation
        - prev_idx
        - next_idx
        - scene_token
        - can_bus
        - frame_idx
        - timestamp
        - img_filename: list,6个视角的图像数据路径
        - lidar2img: list,6个视角 lidar到图像坐标
        - cam_intrinsic: list,6个相机的内参矩阵
        - lidar2cam: list, 6个相机的
        - ann_info: dict,包含`gt_bboxes_3d`,`gt_labels_3d`,`gt_names`..调用`get_ann_info`方法获取
        - 为can_bus中两个数据填充航向信息.倒数第二个是弧度值,最后一个是角度值


    - `load_annotations(self, ann_file)`: 从标注文件中加载标注信息,`data['infos']`并按照时间顺序排序,按照间隔采样
    - `get_ann_info`
   
    -`pre_pipeline`:为调用`get_data_info`方法后获得的数据填充字段


#### LoadMultiViewImageFromFiles
1. 方法
    - `__call__`: 读取原字典中的`img_filename`字段,加载图像数据,增加以下字段
        - filename: 和原字段img_filename一致
        - img: List[ndarray], (num_views,h, w, c )
        - img_shape:
        - ori_shape:
        - pad_shape:
        - scale_factor
        - img_norm_cfg

#### LoadAnnotations3D
1. 方法:
    - `__call__`: 将data中`ann_info`字段中`gt_bboxes_3d`,`gt_labels_3d`放到外层


#### DefaultFormatBundle3D

## BEVformer
1. 数据成员
  

2. 方法
    - `forward_train`:
        - 参数:
            - `points`: None
            - `img_metas`: 每个sample中的meta信息,包含`can_bus`字段
            - `gt_bboxes_3d`: 3d包围框
            - `gt_labels_3d`: label标签
            - `img`: 6个维度,(batch_size, temporal, image_view, C, H, W)
            - ``
        - 功能: 
    - `obtain_history_bev`: 获取历史BEV,在
    - `extract_feat`: 
    - `extract_img_feat`: 提取图像特征 List[Tensor(B, T, N, C, H, W)]
    - ``

## BEVformerHead (DETRHead):
1. 数据成员
    - `bev_h`: 25
    - `bev_w`: 25
    - `fp16_enabled`: 默认为false
    - `with_box_refine`
    - `as_two_stage`: false
    - `code_size`: 10,,?
    - `bbox_coder`:
    - `pc_range`: 点云范围
    - `real_w`: 有效宽度
    - `real_h`: 有效长度
    - `num_cls_fcs`: 1,,???似乎没用到
    - `code_weights`: ????,Parameter
    - ``

    - `bev_embedding`: Embedding(625,256),bev空间为25*25时.
    - `query_embedding`: Embedding(100,512), query为100

2. 方法
    - `forward(self,mlvl_feats, img_metas, pre_bev, only_bev)`:
        1. mlvl_feats: 多尺度特征,tuple[Tensor(B,N,C,H,W)],
        2. pre_bev: Tensor(1, 625, 256)
        3. only_bev: 是否仅仅计算BEV features
        
        4. bev_mask: Tensor(1,25,25)
        5. bev_pos:  对bev中两个方向进行embedding.然后进行concatenate拼接,,Tensor(1,256, 25, 25)
        6. 


## DETRHead
1. 数据成员
    - num_classes: 10
    - in_channels: 256
    - num_query: 100
    - num_reg_fcs: 在用于回归任务头上,全连接层的个数
    - transformer: BEVformer中是`PerceptionTransformer`,
    - syns_cls_avg_factor:
    - positional_encoding: LearnedPositionalEncoding 可学习的位置编码
    - loss_cls: `FocalLoss`
    - loss_bbox: `L1Loss`
    - loss_iou: `GIoULoss`
    - train_cfg: ???
    - 

## LearnedPositionalEncoding 可学习的位置编码(mmdet中的组件)

## PerceptionTransformer 
1. 数据成员
    - `encoder`: `BEVFormerEncoder`中包含TSA和SCA
    - `decoder`: `DetectionTransformerDecoder`
    - `embed_dims`: 256
    - `num_feature_levels`: 似乎是来自FPN的feature_map的个数
    - `num_cams`: camera数量
    - `fp16_enabled`: false
    - `rotate_prev_bev`: true,是否旋转之前的bev
    - `use_shift`: true, 是否使用shift
    - `use_can_bus`: true, 是否使用can_bus信息
    - `can_bus_norm`: True,???
    - `use_cams_embeds`: True,是否使用cams_embeds
    - `two_stage_num_proposals`: 未使用,,在DETR3D中用到
    - `rotate_center`: 旋转中心,,,对于tiny配置的模型,旋转中心
    - `level_embeds`: nn.Parameter, Tensor(4,256), 参数
    - `cams_embeds`: nn.Parameter, Tensor(6,256), 参数
    - `reference_points`: nn.Linear(256, 3) ,子模型
    - `can_bus_mlp`: nn.Sequential 子模型

2. 方法
    - `init_layers`: 进行定义`level_embeds`,`cams_embeds`,`reference_points`,`can_bus_mlp`
    - `init_weights`: 重载方法,对`level_embeds`,`cams_embeds`进行初始化, `reference_points`,`can_bus_mlp`的权重进行`xavier_init`
    - `get_bev_features`:
        1. 参数  
            - `mlvl_feats`: 多尺度特征
            - `bev_queries`: Tensor(2500,256)
            - `bev_h`:
            - `bev_w`:
            - `grid_length`: 每个BEV格子的真实大小 
            - `bev_pos`: positional_encoding得到的bev位置编码 Tensor(1, 256, 50, 50)
            - `prev_bev`: 前一层BEV
        2. 功能:
            - 根据`can_bus`信息,计算前后两帧的在全局坐标下的shift
            - 旋转BEV
            - bev_queries中加入can_bus 经过can_bus_mlp后的 embedding
            - 在 多尺度特征中加入 cams_embedding,和level_embedding
            - 多尺度特征拼接 feat_flatten :(num_cam, h*w, bs, embed_dim)
            - 调用 encoder 模块



## BEVFormerEncoder(继承TransformerLayerSequence)
1. 数据成员
    - `return_intermediate`: 是否返回中间量
    - `num_points_in_pillar`: 一个pillar有4个点
    - `pc_range`: 点云范围
    - `fp16_enabled`:

    - `num_layers`: 
    - `layers`: transformer层 `BEVFormerLayer`,每层含有`TemporalSelfAttention`和`SpatialCrossAttention`

2. 方法
    - `get_reference_points(H, W, Z, num_points_in_pillar, dim, bs, )`:
        - 根据`dim`来判断是获取3d点还是2d点,,分别用在SCA和TSA
        - 如果是`dim==3d`, 返回参考点(bs, num_points, dim, point3d)(1, 4, 2500, 3) ,用于SCA,,归一化后的点
          如果是`dim==2d`, 返回参考点(bs, dim, num_points, point2d)(1, 2500, 1, 2)用于TSA,,归一化后的点
        
    - `point_sampling`:
        - 

## BEVFormerLayer
1. 数据成员
    - attn_cfgs: TSA与SCA的配置
    - feedforward_channels: 隐藏层的维度
    - ffn_dropout
    - operation_order: layer网络顺序('self_attn', 'norm', 'cross_attn', 'norm', 'ffn', 'norm')

## DetectionTransformerDecoder

## TemporalSelfAttention
1. 数据成员
    - norm_cfg 
    - dropout :0.1
    - batch_first: True
    - fp16_enabled: False
    - im2col_step: 64
    - embed_dims: 256
    - num_level: 注意力机制中的feature map 个数,,在TSA中为1
    - num_heads: 8 ,多头注意力个数
    - num_points: 4, 每个查询中采样点个数
    - num_bev_queue: 2, concat 当前bev与历史最近一帧bev
    - sampling_offsets :  ????
    - attention_weights:  ??
    - value_proj: nn.Linear(256,256)
    - output_proj: nn.Linear(256,256)

## mmdetection3D
1. BaseInstance3DBoxes : 定义3D目标检测中实例的包围框的属性与方法
