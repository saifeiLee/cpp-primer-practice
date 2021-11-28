#ifndef PRINT_VEC
#define PRINT_VEC

#include <vector>
#include <iostream>
using namespace std;

template <typename T>
void print_vector(vector<T> vs)
{
    for (const auto &s : vs)
    {
        cout << s << " ";
    }
    cout << " " << endl;
}
template <typename T>
void print_list(list<T> vl)
{
    for (const auto &l : vl)
    {
        cout << l << " ";
    }
    cout << endl;
}

#endif