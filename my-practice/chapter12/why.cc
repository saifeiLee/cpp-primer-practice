#include <iostream>
#include <list>
#include <memory>
using namespace std;

int main()
{
    shared_ptr<string> p1;
    // shared_ptr<list<int>> p2;
    string s("123");
    if (p1 && p1->empty())
    {
        *p1 = s;
    }
    cout << p1->length() << endl;
    // 如何访问p1?
    // cout << *p1 << endl;
    // cout << *p1.get() << endl;

    return 0;
}