#include <memory>
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include "../include/StrBlob.hpp"

using namespace std;
int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        return -1;
    }
    size_t n = stoul(argv[1]);
    allocator<string> alloc;
    auto const p = alloc.allocate(n);
    string s;
    string *q = p;
    while (cin >> s && q != p + n)
    {
        alloc.construct(q++, s);
    }
    const size_t size = q - p;
    cout << size << endl;
    while(q != p)
    {
        cout << *--q << endl;
        alloc.destroy(q);
    }
    alloc.deallocate(p, n);
    return 0;
}