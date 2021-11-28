#include <iostream>
using namespace std;

int main()
{
    int a = 123;
    int *const pnt = &a;
    const double pi = 3.14;
    const double *const pip = &pi;
    return 0;
}