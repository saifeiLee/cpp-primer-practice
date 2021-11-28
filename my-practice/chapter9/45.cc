
#include <vector>
#include <iostream>
#include <list>
#include <string>
#include "./helper.hpp"

using namespace std;

string &format_name(string &s, string prefix, string postfix)
{
    string::iterator bg = s.begin();
    bg = s.insert(bg, 1, ' ');
    s.insert(bg, prefix.begin(), prefix.end());
    s.append(" ");
    s.append(postfix);
    return s;
}

int main()
{
    string str1 = "lsftest";
    string str2 = format_name(str1, "Mr.", "Jr.");
    cout << str2 << endl;
    return 0;
}