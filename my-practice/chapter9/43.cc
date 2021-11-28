
#include <vector>
#include <iostream>
#include <list>
#include <string>
#include "./helper.hpp"

using namespace std;

string &replace_str(string &s, string old_v, string new_v)
{
    auto bg = s.begin();
    string::difference_type len = old_v.size();
    while (s.end() - bg >= len)
    {
        /* code */
        string temp(bg, bg + len);
        if (temp == old_v)
        {
            bg = s.erase(bg, bg + len);
            bg = s.insert(bg, new_v.begin(), new_v.end());
            bg += new_v.size();
        } else {
            ++bg;
        }
    }
    return s;
}

int main()
{
    string str1 = "lsftesttesttest";
    string str2 = replace_str(str1, "test", "ccx");
    cout << str2 << endl;
    return 0;
}