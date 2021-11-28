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
    multimap<string, string> authors = {{"lsf", "zzz"}, {"lsf", "zzc"}, {"lsf", "aaa"}, {"ccx", "123"}};

    map<string, multiset<string>> ordered_authors;
    for (const auto &author : authors)
    {
        ordered_authors[author.first].insert(author.second);
    }
    for (auto &author : ordered_authors)
    {
        cout << "Name: " << author.first << endl;
        for (auto &book : author.second)
        {
            cout << book << " ";
        }
        cout << endl;
    }
    return 0;
}