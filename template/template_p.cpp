#include<iostream>
template <typename T>
auto swap(const T& X)
{
    return std::make_pair(X.second,X.first);
}
int main()
{
    auto x=swap(std::make_pair(7,4.2));
    std::cout<<x.first<<" "<<x.second;
    return 0;
}