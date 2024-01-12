#include <iostream>
struct A {};
template < typename T>
class is_class {
private:
  template <typename C>static char test(int C::*) {
    std::cout << "A class" << std::endl;
    
  }
  template <typename C>static int test(...) {
    std::cout << "Not a class" << std::endl;
  }
  public:
  static constexpr bool value=sizeof(test<T>(0))==1;
};

int main()
{
    std::cout<<is_class<int>::value<<std::endl;
    std::cout<<is_class<A>::value<<std::endl;
    return 0;
}