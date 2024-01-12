#include <iostream>
template<typename T>
void f(int T::*) { std::cout<<"T is class "<<std::endl;}
template<typename T>
void f(...) {std::cout<<"T is not a class"<<std::endl;}
struct A{};
int main()
{
    f<long>(0);
    f<A>(0);
    return 0;
}