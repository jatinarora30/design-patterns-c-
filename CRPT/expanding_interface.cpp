#include <iostream>
template<typename D> struct not_equal
{
    bool operator!=(const D& rhs) const
    {
        return !static_cast<const D*>(this)->operator==(rhs);
    }
};
class C: public not_equal<C>
{
    int i_;
    public:
    C(int i) : i_(i) {}
    bool operator==(const C& rhs) const { return i_ == rhs.i_;}
};