#include <iostream>
template <typename U, typename V>
U half(V x) {return x/2;}

int main()
{
    auto y=half<double>(8.33);
    std::cout<<y<<" type ";
    return 0;
}