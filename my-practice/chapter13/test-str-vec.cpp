#include "./StrVec.hpp"

#include <iostream>
using namespace std;

int main() {
    StrVec s;
    s = {"123", "456"};
    cout << s.size() << endl;
    cout << s << endl;
}