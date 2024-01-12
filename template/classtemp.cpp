#include <iostream>
template <typename T,size_t N>

class Array{
    public:
    T& operator[](size_t i){
        if(i>=N) throw std::out_of_range("Hwww");
        return data_[i];


    }

    private:
    T data_[N];
};


int main()
{
    Array<int,5> a;
    return 0;
}