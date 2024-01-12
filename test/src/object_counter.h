#include<iostream>

struct object_counter {
  static int count;
  static int all_count;
  object_counter();
  ~object_counter();
};


class A
{
public:
int num_return(int a);


};
template <typename T>
class raii
{
public:
  explicit raii(T* p) : p_(p) {}
  ~raii() {delete p_;}
  private:
  T* p_;
};

template <typename T>
class scoped_ptr
{
  public:
  explicit scoped_ptr(T* p) :p_(p) {}
  ~scoped_ptr() {delete p_;}
  T* operator->(){return p_;}
  const T* operator->() const {return p_;}
  T& operator*(){return *p_;}
  const T& operator*() const {return *p_;}
  private:
  T *p_;
};