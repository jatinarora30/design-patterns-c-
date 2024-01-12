#include <iostream>
void f(int i) {std::cout<<"f(int)"<<std::endl;}
// void f(long i) {std::cout<<"f(long)"<<std::endl;}
// template <typename T>
// void f(T i) {std::cout<<"f(T)"<<std::endl;}
// template <typename T>
// void f(T* i) {std::cout<<"f(T*)"<<std::endl;}
struct A 
{};
void f(...) {std::cout<<"f(...)"<<std::endl;}
int main()
{
    f(1);
    f(51121321212132311);
    f(4.0);
    int j=3;
    f(&j);
    A a,c,v,d,s;
    f(a,c,v,d,s,3,45,6,2,3,321,2,3,3);
    return 0;
}
