#include<iostream>
template <typename T>
T sum(T from, T to,T step)
{
    T res = from;
    while((from += step)<to) {res+=from;}
    return res;
}

int main()
{
    std::cout<<sum(1,2,3)<<std::endl;
    return 0;
}