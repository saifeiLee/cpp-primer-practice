#include <memory>
#include <iostream>
#include <string>
#include <vector>
#include <fstream>

using namespace std;

template <typename T, size_t N>
const T *begin(const T (&a)[N])
{
    return &a[0];
}

template <typename T, size_t N>
const T *end(const T (&a)[N])
{
    return &a[0] + N;
}

int main()
{
    int a[3] = {1, 2, 3};
    string b[3] = {"test", "ss", "sdw"};
    auto beg1 = begin(a);
    cout << *beg1 << endl;
    auto end1 = end(a);
    cout << *(end1 - 1) << endl;
    auto beg2 = begin(b);
    cout << *beg2 << endl;
    auto end2 = end(b);
    cout << *(end2 - 1) << endl;
}