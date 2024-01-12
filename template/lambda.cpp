#include <iostream>
#include <vector>
#include <algorithm>
int main()
{
    std::vector<int> v;
    v.push_back(1);
    v.push_back(3);
    v.push_back(0);
    auto compare = [](int i,int j){return i<j;};
    std::sort(v.begin(),v.end(),compare);
    return 0;
}