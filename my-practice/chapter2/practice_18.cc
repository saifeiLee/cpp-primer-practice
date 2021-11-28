#include <iostream>
using namespace std;

int main()
{
    int v1 = 10;
    int v2 = 20;
    int *p1 = &v1;
    cout << "初始变量: " << endl
         << "v1 = " << v1 << endl
         << "v2 = " << v2 << endl
         << "初始指针 -> v1" << endl
         << "p1 值: " << *p1 << endl
         << "p1 地址: " << p1 << endl;
    cout << "-------------------------" << endl;

    p1 = &v2;
    cout << "更改p1 -> p2" << endl;
    cout << "p1 值: " << *p1 << endl;
    cout << "p1 地址: " << p1 << endl;

    return 0;
}