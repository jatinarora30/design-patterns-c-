#include  <iostream>
struct yes
{
    char a;
};
struct no
{
    char a;
    yes c;
};
static_assert(sizeof(yes)!=sizeof(no),"Do someting about structs");
template <typename T> yes test_sort(decltype(&T::sort));
template <typename T> no test_sort(...);
template <typename T,size_t s>
struct fast_sorter_helper;
template<typename T>
struct fast_sorter_helper<T,sizeof(yes)>
{
static void fast_sort(T& x)
{
    std::cout<<"Sorting with T::sort()"<<std::endl;
    x.sort();
}
};
template <typename T>
struct fast_sorter_helper<T,sizeof(no)>
{
static void fast_sort(T& x)
{
    std::cout<<"Sorting with std::sort()"<<std::endl;
}
};
template <typename T>
void fast_sort(T& x)
{
    fast_sorter_helper<T,sizeof(test_sort<T>(NULL))>::fast_sort(x);
}
class A
{
    public:
void sort() {}
};
class B
{
    public:
    void f() {}
};
int main()
{
    A a;
    B b;
    fast_sort(a);
    fast_sort(b);
    return 0;
}
























