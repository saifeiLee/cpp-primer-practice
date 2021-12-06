#include <memory>
#include <iostream>
#include <string>
#include <vector>
#include <fstream>

using namespace std;

// template <typename T, size_t N>
// void print(const T (&a)[N])
// {
//     for (auto iter = begin(a); iter != end(a); ++iter)
//     {
//         cout << *iter << " ";
//     }
//     cout << endl;
// }

template <typename T>
void print(const T *a)
{
    cout << *a << endl;
}

int main()
{

    int a[3] = {1, 2, 3};
    string b[3] = {"test", "ss", "sdw"};
    print(a);
    print(b);

    print(a);
    print(b);
    return 0;
}