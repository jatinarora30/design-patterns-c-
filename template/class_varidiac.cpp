#include<iostream>
template <typename ... T>
struct Group;
template <typename T1>
struct Group<T1>{
    T1 t1_;
    Group() =default;
    explicit Group(const T1& t1):t1_(t1) {}
    explicit Group(T1&& t1): t1_(std::move(t1)) {}
    explicit operator const T1&() const {return t1_;}
    explicit operator T1&() {return t1_;}

};
template <typename T1, typename ... T>
struct Group<T1,T ...>{
    T1 t1_;
    Group() =default;
    explicit Group(const T1& t1,T&& ... t):t1_(t1) {}
    explicit Group(T1&& t1): t1_(std::move(t1)) {}
    explicit operator const T1&() const {return t1_;}
    explicit operator T1&() {return t1_;}

};

int main()
{
    return 0;
}