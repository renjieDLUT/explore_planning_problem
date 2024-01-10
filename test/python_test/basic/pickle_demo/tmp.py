import pickle
from random import shuffle

data={"name":"renjie","age":29}

class Foo:
    def __init__(self):
        self.name="renji"
        self.age=29
    
    def __str__(self):
        return f'name:{self.name}, age:{self.age}'
    
    

f=Foo()

serialized_data=pickle.dumps(f)

f1=pickle.loads(serialized_data)

print(f1,type(f1))

data=[1,2,3,4,5,6]
shuffle(data)
print(data)
