#include <iostream>
class Base
{
public:
Base() : i_() {}
virtual void increment(long v) {i_+=v;}
long i_=0;
};

template<typename T>
class Derived: public T{
public:
    Derived() :T() , j_() {}
    void increment(long v) {j_ += v; T::increment(v);}
    void multiply(long v) {j_*=v ; T::multiply(v);}
    long j_=0;
};

int main()
{
    Derived<Base> d;
    d.increment(5);
    std::cout<<d.i_<<" "<<d.j_;
    return 0;
}