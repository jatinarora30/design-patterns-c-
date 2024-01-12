#include <iostream>
struct NoDebug {
  template <typename T> static void constructed(const T *p) {}
  template <typename T> static void destructed(const T *p) {}
};

struct Debug {
  template <typename T> static void constructed(const T *p) {std::cout<<"Constructed "<<static_cast<const void*>(p)<<std::endl;}
  template <typename T> static void destructed(const T *p) {std::cout<<"Destructed"<<static_cast<const void*>(p)<<std::endl;}
};
template <typename T> struct DeleteByOPerator {
  void operator()(T *p) const {
    std::cout << "Delete" << std::endl;
    delete p;
  }
};
struct WithArrow
{
  static constexpr bool with_arrow=true;
};

struct WithoutArrow
{
  static constexpr bool with_arrow=false;
};

template <typename T, typename DeletetionPolicy, typename DebugPolicy = NoDebug,typename ArrowPolicy = WithArrow>
class SmartPtr {
public:
  explicit SmartPtr(T *p = nullptr, const DeletetionPolicy &deletion_policy =
                                        DeletetionPolicy())
      : p_(p), deletion_policy_(deletion_policy) {
    std::cout << "Start" << std::endl;
    DebugPolicy::constructed(p_);
  }
  std::enable_if_t<ArrowPolicy::with_arrow,T*> operator->(){ return p_;}
  ~SmartPtr() {
    deletion_policy_(p_);
    DebugPolicy::destructed(p_);
  }
  const T *operator->() const { return p_; }
  T &operator*() { return *p_; }
  const T &operator*() const { return *p_; }

private:
  T *p_;
  DeletetionPolicy deletion_policy_;
  SmartPtr(const SmartPtr &) = delete;
  SmartPtr &operator=(const SmartPtr &) = delete;
};


class C {};

int main() {
  SmartPtr<C, DeleteByOPerator<C>,Debug> p(new C);
  SmartPtr<C, DeleteByOPerator<C>,Debug> p2(new C);
  return 0;
}