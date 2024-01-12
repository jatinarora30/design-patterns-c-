#include <algorithm>
#include <iostream>
struct yes {
  char a;
};
struct no {
  char a;
  yes c;
};
static_assert(sizeof(yes) != sizeof(no), "Do someting about structs");
template <typename T> yes test_sort(decltype(&T::sort));
template <typename T> no test_sort(...);
template <typename T> yes test_range(decltype(&T::begin), decltype(&T::end));
template <typename T> no test_range(...);
template <typename T, bool have_sort, bool have_range> struct fast_sort_helper;
template <typename T> struct fast_sort_helper<T, true, true> {
  static void fast_sort(T &x) {
    std::cout << "Sorting with T::sort, ignoring end,begin" << std::endl;
    x.sort();
  }
};

template <typename T> struct fast_sort_helper<T, false, true> {
  static void fast_sort(T &x) {
    std::cout << "Sorting with std::sort" << std::endl;
    std::sort(x.begin(), x.end());
  }
};

template <typename T> struct fast_sort_helper<T, true, false> {
  static void fast_sort(T &x) {
    std::cout << "Sorting with T::sort" << std::endl;
    x.sort();
  }
};

template <typename T> struct fast_sort_helper<T, false, false> {
  static void fast_sort(T &x) { std::cout << "Hwww" << std::endl; }
};
template <typename T> void fast_sort(T &x) {
  fast_sort_helper<T, sizeof(test_sort<T>(NULL)) == sizeof(yes),
                   sizeof(test_range<T>(NULL, NULL)) ==
                       sizeof(yes)>::fast_sort(x);
}

class AB {
public:
  void sort() {}
  int *begin() { return i; }
  int *end() { return i + 10; }
  int i[10];
};
class C {
public:
  int *begin() { return i; }
  int *end() { return i + 10; }
  int i[10];
};
class A {};
class B {
public:
  void sort() {}
};

int main() { 
    A a;
    B b;
    C c;
    AB ab;
    fast_sort(a);
    fast_sort(b);
    fast_sort(c);
    fast_sort(ab);
    return 0;
     }