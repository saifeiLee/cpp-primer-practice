
#include <vector>
#include <iostream>
#include <list>
#include <string>
#include "./helper.hpp"

using namespace std;

int main()
{
    string s("ab2c3d7R4E6");
    string number("0123456789");
    string albetical("abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ");
    string::size_type pos = 0;
    while ((pos = s.find_first_of(number, pos)) != string::npos)
    {
        /* code */
        cout << s[pos];
        ++pos;
    }
    cout << endl;
    pos = 0;
    while ((pos = s.find_first_of(albetical, pos)) != string::npos)
    {
        cout << s[pos];
        ++pos;
    }
    cout << endl;
    return 0;
}