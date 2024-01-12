#include <iostream>
class C
{
    int x_;
    public:
    C(int x) : x_(x) {}
    friend std::ostream& operator<<(std::ostream& out, const C& c)
    {
        out<<c.x_;
        return out;
    }
};
int main()
{
    C c1(5),c2(7);
    std::cout<<c1<<c2;
}