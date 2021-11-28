#include <iostream>
#include <vector>

using namespace std;

int add(int x, int y)
{
    return x + y;
}

int subtract(int x, int y)
{
    return x - y;
}

int multiply(int x, int y)
{
    return x * y;
}

int divide(int x, int y)
{
    return y != 0 ? x / y : 0;
}

int main()
{
    typedef decltype(add) *FP;
    vector<FP> arithmetic_vec = {add, subtract, multiply, divide};
    for (auto arithmetic_operator: arithmetic_vec) {
        cout << arithmetic_operator(10, 10) << endl;
    }

    return 0;
}