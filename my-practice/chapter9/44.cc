
#include <vector>
#include <iostream>
#include <list>
#include <string>
#include "./helper.hpp"

using namespace std;

string &replace_str(string &s, string old_v, string new_v)
{
   decltype(s.size()) len = old_v.size(), index = 0;
   while (s.size() - index >= len)
   {
       string temp = s.substr(index, len);
       if (temp == old_v) {
           s.replace(index, len, new_v);
           index += new_v.size();
       } else {
           ++index;
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