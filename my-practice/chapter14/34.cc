#include <memory>
#include <iostream>
#include <string>
#include <vector>
#include <fstream>

using namespace std;
class Condition
{
public:
    int operator()(int a, int b, int c)
    {
        if (a)
        {
            return b;
        }
        else
        {
            return c;
        }
    }
};
int main()
{
    Condition c;
    int a = c(0, 2, 3);
    cout << a << endl;
    return 0;
}