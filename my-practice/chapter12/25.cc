#include <memory>
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include "../include/StrBlob.hpp"

using namespace std;
int main()
{
    vector<int> ivec;
    ivec.push_back(1);
    ivec.push_back(2);
    ivec.push_back(3);
    allocator<int> alloc;
    auto p = alloc.allocate(ivec.size() * 2);
    auto q = uninitialized_copy(ivec.begin(), ivec.end(), p);
    uninitialized_fill_n(q, ivec.size(), 42);
    for (auto i = p; i != q; ++i)
        cout << *i << endl;
    return 0;
}