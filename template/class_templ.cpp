#include <iostream>
using namespace std;
template <typename N,typename D>
class Ratio
{
    private:
    N num_;
    D dem_;

    public:
    Ratio(): num_(),dem_(){}
    Ratio(const N& num,const D& dem) : num_(num), dem_(dem){}
    explicit operator double() const { return double(num_)/double(dem_);}
};
template <>
class Ratio<double,double>
{
    private:
    double value_;

    public:
    Ratio(): value_(){}
    template <typename N,typename D>
    Ratio(const N& num,const D& dem) : value_(double(num)/double(dem)){}
    explicit operator double() const { return value_;}
};
template <typename N, typename D>
class Ratio<N*,D*>
{
    private:
    N* const num_;
    D* const dem_;

    public:
    Ratio( N* num,D* dem) : num_(num), dem_(dem){}
    explicit operator double() const { return double(*num_)/double(*dem_);}
};


int main()
{
    Ratio<int,double> r(5,0.1);
    std::cout<<double(r)<<std::endl;
    double i=10.0;
    int x=4;
     // Create pointers
    double* ptr_i = &i;
    int* ptr_x = &x;

    Ratio<double*, int*> r2(ptr_i, ptr_x);
    std::cout << double(r2) << std::endl;

    x = 5;
    std::cout << double(r2) << std::endl;
    x=2;
    std::cout << double(r2) << std::endl;
    return 0;
}

