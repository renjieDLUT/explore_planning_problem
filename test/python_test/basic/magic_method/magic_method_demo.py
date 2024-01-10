# =========================== __getattr___  ============================

class Foo:
    def __init__(self, num, name):
        self.data = dict()
        self.data["num"] = num
        self.data["name"] = name

    def __getattr__(self, name):
        if name in self.data:
            return self.data[name]
        else:
            raise AttributeError


f = Foo(10,"renjie")
print(f.name)
