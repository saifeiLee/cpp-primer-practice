#include <iostream>

using std::cout;
using std::endl;

void reset(int &x)
{
    x = 0;
}

int main() {
    int testValue = 42;
    reset(testValue);
    cout << testValue << endl;
    return 0;
}