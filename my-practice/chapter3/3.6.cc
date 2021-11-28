
#include <iostream>
#include <string>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;

int main()
{
    vector<string> v1{"a"};
    for (auto str : v1)
    {
        cout << str << endl;
    }
    return 0;
}