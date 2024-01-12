template<typename T>
class smartptr
{
struct delete_base{
    virtual void apply(void*) = 0;
    virtual ~delete_base() {}
};
template<typename Deleter>
struct deleter : public delete_base
{
    deleter(Deleter d): d_(d) {}
    virtual void apply(void* p) { d_(static_cast<T*>(p)); }

    Deleter d_;
};

public:
template <typename Deleter> smartptr(T* p, Deleter d) : p_(p), d_(new deleter<Deleter>(d)) {}
~smartptr() { d_->apply(p_); delete d_;}
T* operator->() {return p_;}
const T* operator->() const {return p_;}
private:
T* p_;
delete_base* d_;
};