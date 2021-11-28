#include <iostream>
#include <stdexcept>
using namespace std;

int main()
{
    int a = 1, b = 2;
    try
    {
        if (a != b)
        {
            throw runtime_error("a and b should be equal");
        }
    }
    catch (std::runtime_error error)
    {
        cout << error.what() << endl;
    }
    return 0;
}