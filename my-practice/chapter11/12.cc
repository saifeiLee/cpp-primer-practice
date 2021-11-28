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
    vector<pair<string, int>> vec;
    vector<string> vs = {"test", "hello"};
    vector<int> vi = {1, 2};
    auto vs_begin = vs.begin();
    auto vi_begin = vi.begin();
    while (vs_begin != vs.end() && vi_begin != vi.end())
    {
        /* code */
        // vec.push_back(make_pair(*vs_begin, *vi_begin));
        vec.emplace_back(*vs_begin, *vi_begin);
        ++vs_begin;
        ++vi_begin;
    }
    
    return 0;
}