#include <memory>
#include <iostream>
#include <string>
#include <vector>
#include <fstream>

using namespace std;

template <typename T, size_t N>
constexpr int arr_size(const T (&a)[N])
{
    return N;
}

int main()
{
    int a[3] = {1, 2, 3};
    int size = arr_size(a);
    cout << size << endl;
    return 0;
}