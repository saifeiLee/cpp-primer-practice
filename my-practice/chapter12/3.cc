#include <memory>
#include <iostream>
#include <string>
#include <vector>
#include <new>

using namespace std;
int main()
{
    string *ps = new string;
    cout << *ps << endl;
    int *pi = new int;
    cout << *pi << endl;

    int *pi2 = new int(1024);
    string *ps2 = new string(10, '9');
    cout << *pi2 << endl;
    cout << *ps2 << endl;

    //
    int *p2 = new (nothrow) int;
    if (p2) {
        cout << "OK" << endl;
    }
    delete ps;
    delete pi;
    return 0;
}