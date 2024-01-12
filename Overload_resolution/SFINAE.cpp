#include <iostream>
template <typename T> void f(T *i) { std::cout << "f(T*)" << std::endl; }

template <typename T> void f(int T::*i) { std::cout << "f(T::*)" << std::endl; }
struct A {
  int i;
};
template <size_t N> void f(char (*)[N % 2] = NULL) {std::cout<<"N = "<<N<<" is odd"<<std::endl;}
template <size_t N> void f(char (*)[1- N % 2] = NULL) {std::cout<<"N = "<<N<<" is even"<<std::endl;}
int main() {
  A a;
  f(&a.i);
  f(&A::i);
  int i;
  f(&i);
  f<5>();
  f<8>();
  return 0;
}