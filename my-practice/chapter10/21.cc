#include <algorithm>
#include <vector>
#include <iostream>
#include <list>
#include <string>

using namespace std;

int main(int argc, char *argv[])
{
    int i = 6;
    auto fn = [&i]() -> bool
    {
        if (i > 0)
        {
            while (i > 0)
            {
                /* code */
                --i;
            }
            return true;
        } else {
            return false;
        }
    };
    bool b = fn();
    cout << b << endl;
    return 0;
}