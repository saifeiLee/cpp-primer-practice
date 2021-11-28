#include <memory>
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include "../include/StrBlob.hpp"

using namespace std;
int main()
{
    constexpr size_t sz = 3;
    string s;
    cin >> s;
    size_t count;
    if (s.size() < sz) {
        count = s.size();
    } else {
        count = sz;
    }
    char *p = new char[sz];
    for (size_t i = 0; i < count; ++i) {
        p[i] = s[i];
    }
    for (size_t i = 0; i < count; ++i) {
        cout << p[i];
    }
    delete[] p;
    return 0;
}