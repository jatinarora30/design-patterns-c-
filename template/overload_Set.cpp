#include<iostream>
template <typename ... F> struct overload_set;
template <typename F1>
struct overload_set<F1> : public F1
{
    overload_set(F1&& f1) : F1(std::move(f1)) {}
    overload_set(F1&& f1) : F1(f1) {}
    using F1::operator();

};

template <typename F1,typename ... F>
struct overload_set<F1,F ... >: public F1, public overload_set<F ...>{
overload_set(F1&& f1, F&& ... f):   F1(std::move(f1)),overload_set<F ...>(std::forward<F>(f) ...){}
overload_set(F1&& f1, F&& ... f):   F1(f1),overload_set<F ...>(std::forward<F>(f) ...){}
using F1::operator();
};

template <typename F>
auto overload(F&& f)
{
    return overload_set<F ...> (std::forward<F>(f) ...);
}

int main()
{
    return 0;
}