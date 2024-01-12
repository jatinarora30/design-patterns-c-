#include<iostream>
void whatami(int x) {std::cout<<x<<" is a int"<<std::endl;}
void whatami(float x) {std::cout<<x<<" is a float"<<std::endl;}
template <typename T>
void whatami(T* x) {std::cout<<x<<" is a poninter"<<std::endl;}
int main()
{
    int x=5;
    whatami(x);
    float y=2.0;
    whatami(y);
    x++;
    whatami(&x);

    return 0;

}