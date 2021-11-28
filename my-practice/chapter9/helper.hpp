#ifndef HELPER
#define HELPER

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
    cout << " ";
}

#endif