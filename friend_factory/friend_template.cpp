#include <iostream>
template <typename T> class C {
  T x_;

public:
  C(T x) : x_(x) {}
  template <typename U> friend C<U> operator+(const C<U> lhs, const C<U> rhs) {
    return C<U>(lhs.x_ + rhs.x_);
  }
  template <typename U>
  friend std::ostream &operator<<(std::ostream &out, const C<U> &obj) {
    out << obj.x_;
    return out;
  }
};
int main() {
  C<int> c1(1), c2(2);
  std::cout << c1 + c2;
  return 0;
}