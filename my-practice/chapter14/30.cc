#include "../include/StrBlob.hpp"
#include <iostream>
#include <vector>

using namespace std;

int main() {
    StrBlob a1 = {"himi", "hello", "world"};
    StrBlobPtr p(a1);
    cout << *p << endl;
    cout << p->size() << endl;
    cout << (*p).size() << endl;
    return 0;
}