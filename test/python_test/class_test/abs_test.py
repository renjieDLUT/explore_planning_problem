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