#include <iostream>

using namespace std;

void f() {
    cout << "Empty param list" << endl;
}

void f(int) {
    cout << "int" << endl;
}

void f(int, int) {
    cout << "int int" << endl;
}

void f(double, double) {
    cout << "double, double" << endl;
}

int main() {
    // a: error, 多义调用
    // f(2.56, 42);
    // b: int
    f(42);
    // c: int int
    f(42, 0);

    // d: double double
    f(2.56, 3.14);
    return 0;
}