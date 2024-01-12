#include <iostream>
class Bird
{
    public:
    virtual void fly()=0;
   
};


class Vulture: public Bird
{
    public:
     void fly() override
    {
        std::cout<<"Vulture fly"<<std::endl;
    }
};


class Eagle: public Bird
{
    public:
     void fly() 
    {
        std::cout<<"Eagle fly"<<std::endl;
        
    }
};
void hunt(Bird& b)
{
    b.fly();
}

int main()
{

    Eagle e;
    hunt(e);
    Vulture v;
    hunt(v);
    return 0;
}