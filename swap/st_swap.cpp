#include <iostream>
using namespace std;

template <typename T>
void myswap(T& x,T& y)
{
    T temp=x;
    x=y;
    y=temp;
}
int main()
{
    int a=1,b=2;
    std::cout<<"a "<<a<<" b "<<b<<std::endl;
    myswap(a,b);
    std::cout<<"a "<<a<<" b "<<b<<std::endl;
    return 0;
}