#include <algorithm>
#include <vector>
#include <iostream>
#include <list>
#include <string>
#include <map>
#include <set>
#include "../include/print_vec.hpp"

using namespace std;
int main(int argc, char *argv[])
{
    map<string, vector<string>> family;
    family["lsf"] = vector<string>{"Tom", "Jack"};
    family["lsf"].push_back("Test");
    for (const auto &p : family)
    {
        cout << "Family " << p.first << " members " << endl;
        for (const auto &s : p.second)
        {
            cout << s << " ";
        }
        cout << endl;
    }
    return 0;
}