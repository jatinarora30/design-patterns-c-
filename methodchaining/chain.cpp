#include <iostream>
int main()
{
    int i=2,j=3;
    auto& out1 = std::cout.operator<<(i).operator<<(" ").operator<<(j);
   

    return 0;
}