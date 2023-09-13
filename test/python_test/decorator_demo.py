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
