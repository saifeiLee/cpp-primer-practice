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
    multiset<int> c = {1, 2, 3};
    vector<int> v = {14, 5, 6};
    copy(v.begin(), v.end(), inserter(c, c.end()));
    // copy(v.begin(), v.end(), back_inserter(c));
    copy(c.begin(), c.end(), inserter(v, v.end()));
    copy(c.begin(), c.end(), back_inserter(v));
    
    print_vector(v);
    return 0;
}