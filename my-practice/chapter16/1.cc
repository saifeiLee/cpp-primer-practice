#include <iostream>
#include <string>

using namespace std;

template <typename T>
inline int compare(const T &v1, const T &v2)
{
    if (v1 < v2)
        return -1;
    if (v2 < v1)
        return 1;
    return 0;
}

namespace lsf
{
    int age = 0;
    string name = "123";
}

template <unsigned N, unsigned M>
int compare(const char (&p1)[N], const char (&p2)[M])
{
    return strcmp(p1, p2);
}

class Base
{
public:
    string name;
};

int main()
{
    // test int
    int res1 = compare(1, 2);
    // test double
    int res2 = compare(1.1, 2.2);
    // cout << res1 << " " << res2 << endl;
    int res3 = compare("hello", "hi");
    // cout << res3 << endl;
    Base b1, b2;
    int res4 = compare(b1, b2);
    cout << res4 << endl;
    return 0;
}
