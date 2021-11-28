

#include <vector>
#include <iostream>
#include <list>
#include <string>
#include <forward_list>
#include "./helper.hpp"

using namespace std;

int main()
{
    forward_list<int> fli = {0, 1, 2, 3, 4, 5, 6, 7};
    auto prev = fli.before_begin();
    auto bg = fli.begin();
    while (bg != fli.end())
    {
        if (*bg % 2 != 0)
        {
            bg = fli.erase_after(prev);
        }
        else
        {
            prev = bg;
            ++bg;
        }
    }
    for (auto &i : fli)
    {
        cout << i << endl;
    }
    return 0;
}