#include<iostream>
template <typename ... T>
auto sum(const T& ... x)
{
    return (x + ...);
}


int main()
{
    std::cout<<sum(5,8,7,5)<<std::endl;
    return 0;
}