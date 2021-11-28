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
int main(int argc, char *argv[])
{   
    multimap<string, string> family;
    family.insert({"lsf", "111"});
    family.insert({"lsf", "222"});

    for(auto &s: family) {
        cout << s.second << " ";
    }
    cout << endl;
    return 0;
}