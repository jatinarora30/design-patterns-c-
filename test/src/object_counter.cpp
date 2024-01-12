#include "object_counter.h"

int object_counter::count = 0;
int object_counter::all_count = 0;

object_counter::object_counter() {
    ++count;
    ++all_count;
}

object_counter::~object_counter() {
    --count;
}

int A::num_return(int a)
{
    std::cout<<a*2<<std::endl;
    return a*2;
} 