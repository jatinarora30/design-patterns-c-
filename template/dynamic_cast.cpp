#include <iostream>
class Base {
    public:
    virtual void s()
    {
        std::cout<<"Base "<<std::endl;
    }
};
class Derived: public Base{
    public:
virtual void s()
{
        std::cout<<"Derived "<<std::endl;
}
};
int main()
{
    Base* b1 =new Derived;
    Base* b2 =new Base;
    Derived* d1=dynamic_cast<Derived*>(b1);
    Derived* d2=dynamic_cast<Derived*>(b2);
    std::cout<<d1 <<" "<<d2<<std::endl;
    return 0;
}