
#include <vector>
#include <iostream>
#include <list>
#include <string>
#include <forward_list>
#include "./helper.hpp"

using namespace std;

using flst = forward_list<string>;

flst insert_str_after_str(flst &l, string str1, string str2)
{
    auto bg = l.begin();
    auto temp = bg;
    while (bg != l.end())
    {
        /* code */
        if (*bg == str1)
        {
            // insert after bg
            l.insert_after(bg, str2);
            return l;
        }
        else
        {
            temp = bg;
            ++bg;
        }
        l.insert_after(temp, str1);
    }

    return l;
}

int main()
{
    flst ls_1 = {"lsf", "ccx", "test", "fun"};
    flst ls_2 = insert_str_after_str(ls_1, "lsf", "like");
    for (const auto &s : ls_2)
    {
        cout << s << " ";
    }
    cout << endl;
    return 0;
}