
#include <vector>
#include <iostream>
#include <list>
#include <string>
#include "./helper.hpp"

using namespace std;

int main()
{
    int i = 42;
    string s = to_string(i);
    cout << s << endl;
    cout << stoi(s) << endl;

    string s2 = "pi = 0XAB";
    int d =stod(s2.substr(s2.find_first_of("+-.0123456789")));
    cout << d << endl;
    return 0;
}