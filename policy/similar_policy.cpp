#include<iostream>
template<typename T, template<typename,typename> class ... Policies>
class Value: public Policies<T,Value<T,Policies ...>> ...
{
    public:
    typedef T value_type;
    explicit Value() : val_(T()) {}
    explicit Value(T v) : val_(v) {}
    Value(const Value& rhs): val_(rhs.val_) {}
    Value& operator=(Value rhs) {val_=rhs.val_; return *this;}
    Value& operator=(T rhs){val_=rhs; return *this;}
    friend std::ostream& operator<<(std::ostream& out, Value x)
    {
        out<<x.val_;
        return out;
    }
    friend std::ostream& operator>>(std::ostream& out, Value x)
    {
        out>>x.val_;
        return out;
    }
    T get() const {return val_;}
    T& get() {return val_;}

    private:
    T val_;
};
template<typename T,typename V>
struct Incrementable{
V operator++()
{
    V& v = static_cast<V&>(*this);
    ++(v.get());
    return v;
}

V operator++(int)
{
    V& v = static_cast<V&>(*this);
    return V(v.get()++);
}
};

 int main() {
    using V = Value<int,Incrementable>;
    V v0(0),v1(1);
    v1++;
    v0++;
    std::cout<<v1<<" "<<v0;
    return 0;
}