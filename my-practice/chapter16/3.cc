#include <memory>
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <list>

using namespace std;

template <typename I, typename T>
I _find(I b, I e, const T &v)
{
    while (b != e && *b != v)
    {
        b++;
    }
    return b;
}

int main()
{
    vector<int> vi = {0,
                      2,
                      4,
                      6,
                      8};
    list<string> ls = {"hello", "world", "~"};
    auto iter = _find(vi.begin(), vi.end(), 6);
    cout << *iter << endl;
    return 0;
}