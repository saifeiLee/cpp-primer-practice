#include <algorithm>
#include <vector>
#include <iostream>
#include <list>
#include <string>
#include "../include/print_vec.hpp"

using namespace std;
int main(int argc, char *argv[])
{
    vector<int> vec;
    for (int i = 0; i < 10; ++i)
    {
        vec.push_back(i);
    }
    vector<int> vec2;
    copy(vec.rbegin() + 3, vec.rbegin() + 8, inserter(vec2, vec2.begin()));
    // print_vector(vec2);
    for (auto &i : vec2)
    {
        cout << i << endl;
        // cout << vec2.size() << endl;
    }
    return 0;
}