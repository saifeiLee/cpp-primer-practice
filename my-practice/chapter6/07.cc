#include <iostream>

using std::cout;
using std::endl;

int callCounter()
{
    static int executionCount = 0;
    return ++executionCount;
}
int main()
{
    for (auto i = 0; i != 10; ++i) {
        cout << callCounter() << endl;
    }
    return 0;
}