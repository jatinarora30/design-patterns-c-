#include <iostream>
class Base
{
    public:
    virtual void f()
    {
        std::cout<<"Base::f()"<<std::endl;
    }
    void g() {f();}
};

class Derived : private Base
{
    public:
    virtual void f()
    {
        std::cout<<"Derived::f()"<<std::endl;
    }
    void h(){g();}
};
int main()
{
    Derived d;
    d.h();
    return 0;
}