#include <iostream>
using namespace std;

int main()
{
    int iVal = 1024;
    int &refVal = iVal;
    double v2 = 0, &v2Ref = v2;
    v2Ref = 3.14;
    cout << v2Ref << endl;
    return 0;
}