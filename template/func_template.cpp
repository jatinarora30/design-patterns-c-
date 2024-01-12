#include <iostream>
template <typename T>
T increment(T x)
{
    return x++;
}

int main()
{
    std::cout<<increment(5)<<std::endl;
    std::cout<<increment(6.2)<<std::endl;
    char c[10];
    std::cout<<increment(c)<<std::endl;
}