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
    map<int, int> sample = {{1, 2}};
    auto beg = sample.begin();
    beg->second = 3;
    while (beg != sample.end())
    {
        /* code */
        cout << beg->second << " ";
        ++beg;
    }
    cout << endl;
    return 0;
}