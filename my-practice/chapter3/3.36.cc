#include <iostream>
#include <string>
#include <vector>

using std::begin;
using std::cin;
using std::cout;
using std::end;
using std::endl;
using std::string;
using std::vector;

int main()
{
    int firstArray[3] = {1, 2, 3};
    int secondArray[3] = {4, 5, 6};
    int *ptr2element = secondArray;

    if (end(firstArray) - begin(firstArray) ==
        end(secondArray) - begin(secondArray))
    {
        for (auto element : firstArray)
        {
            if (element != *ptr2element)
            {
                cout << "Not match" << endl;
                return -1;
            }
        }
        ++ptr2element;
    }
    else
    {
        cout << "不相等" << endl;
        return -1;
    }
    return 0;
}