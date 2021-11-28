#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::string;

int main()
{
    string firstString = "Hello";
    string secondString = "Helloo";
    if (firstString == secondString) {
        cout << "相等" << endl;
    } else if (firstString < secondString) {
        cout << firstString << "小于" << secondString << endl;
    } else {
        cout << firstString << "大于" << secondString << endl;
    }
    return 0;
}