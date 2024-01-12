#include <iostream>
template<typename D> class B
{
    public:
    void f(int i) {static_cast<D*>(this)->f_impl(i);}
    private:
    void f_impl(int i) {}
};

class D: public B<D>
{
    private:
    void f_impl(int i){std::cout<<"D->I"<<std::endl;}
    friend class B<D>;
};
class D1: public B<D1>
{
    private:
    void f_impl(int i){std::cout<<"D1->I"<<std::endl;}
    friend class B<D1>;
};
int main()
{
    B<D>* b = new D;
    B<D1>* b1 =new D1;
    b->f(3);
    b1->f(3);

    return 0;
}