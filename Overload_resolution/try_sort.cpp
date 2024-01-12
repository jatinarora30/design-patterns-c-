#include <iostream>
#include <algorithm>
template <typename T> void best_sort(T &x, bool use_member_sort) {
  if (use_member_sort)
    x.sort();
  else {
    std::sort(x.begin(), x.end());
  }
}
class A
{
    int arr[10];
    public:
    void sort() {std::cout<<"hwww";}
    int* begin() { return arr; }
  int* end() { return arr + 10; }

};

int main() {
    A a;
    best_sort(a,true);

    return 0; }