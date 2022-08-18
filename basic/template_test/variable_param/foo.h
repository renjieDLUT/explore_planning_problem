#include <iostream>
using std::cout, std::endl;

void f() { cout << "pargs size=0\t Do nothing,quit." << endl; }

template <typename T, typename... Args>
void f(T first, Args... args) {
  cout << "pargs size = " << sizeof...(args) + 1;
  cout << "current value type = " << typeid(T).name();
  cout << "current value = " << first << endl;
  f(args...);
}

template <typename... Args>
void g(Args... args) {
  cout << "g:\n\targs size= " << sizeof...(args) << "\tCall f(&args...):\n";
  f(args...);
  cout << endl;
  f(&args...);
}