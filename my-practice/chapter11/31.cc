#include <algorithm>
#include <vector>
#include <iostream>
#include <list>
#include <string>
#include <map>
#include <set>
#include <utility>
#include "../include/print_vec.hpp"

using namespace std;

void safe_erase(multimap<string, string> &authors, string name)
{
    multimap<string, string>::iterator iter;
    while ((iter = authors.find(name)) != authors.end())
    {
        authors.erase(iter);
    }
}

void print_multi_map(multimap<string, string> &authors)
{
    for (auto beg = authors.begin(); beg != authors.end(); ++beg)
    {
        cout << beg->first << " " << beg->second << endl;
    }
}
int main(int argc, char *argv[])
{
    multimap<string, string> authors = {{"lsf", "111"}, {"lsf", "222"}, {"lsf", "222"}, {"ccx", "123"}};
    cout << "Original map: " << endl;
    print_multi_map(authors);
    safe_erase(authors, "lsf");
    cout << "After erase lsf:" << endl;
    print_multi_map(authors);
    return 0;
}