#include <iostream>
class Base
{
    public:
    virtual bool step1() { std::cout<<"Base Step 1"<<std::endl; return true;}
    virtual void step2()=0;
    bool algorithm()
    {
        step1();
        step2();
    }
};

class D1: public Base
{
    public:
    void step2() {std::cout<<"D1 Step 2"<<std::endl; }
};
class D2: public Base
{
    public:
    bool step1() {std::cout<<"D2 Step 1"<<std::endl; return true;}
    void step2() {std::cout<<"D2 Step 2"<<std::endl; }
};

int main()
{
    D1 d1;
    D2 d2;
    d1.algorithm();
    d2.algorithm();
}