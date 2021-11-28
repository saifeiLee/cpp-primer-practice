#include <iostream>

using namespace std;

int main()
{
    int i = 42;
    int *p = nullptr;
    int *&r = p;
    r = &i;
    *r = 1;
    cout << *r << endl;
    return 0;
}