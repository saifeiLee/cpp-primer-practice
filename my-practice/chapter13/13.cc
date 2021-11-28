#include <memory>
#include <iostream>
#include <string>
#include <vector>
#include <fstream>

using namespace std;
struct X
{
    X() { cout << "X()" << endl; }
    X(const X &) { cout << "X(const X&)" << endl; }
    X &operator=(const X &)
    {
        cout << "X &operator=(const X&)" << endl;
        return *this;
    }
    ~X() { cout << "~X()" << endl; }
};

void test(X &x)
{
    cout << "test(X&)" << endl;
}
void test2(X) {
    cout << "test2(X)" << endl;
}

int main()
{
    X x1;
    X x2 = x1;
    X *x3 = new X; // 没有调用拷贝构造函数？？？
    test(x1);      
    test2(x1);  
    X ax[] = {x1, x2, *x3};
    delete x3;
}