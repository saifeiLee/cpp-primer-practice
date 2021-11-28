
#include <vector>
#include <iostream>
#include <list>
#include <string>
#include "./helper.hpp"

using namespace std;

string &format_name(string &s, string prefix, string postfix)
{
    s.insert(0, " ");
    s.insert(0, prefix);
    s.insert(s.length(), " ");
    s.insert(s.length(), postfix);
    return s;
}

int main()
{
    string str1 = "lsftest";
    string str2 = format_name(str1, "Mr.", "Jr.");
    cout << str2 << endl;
    return 0;
}