#include <algorithm>
#include <vector>
#include <iostream>
#include <list>
#include <string>
#include "../include/print_vec.hpp"

using namespace std;
int main(int argc, char *argv[])
{
    vector<int> vi = {1, 2, 3, 3, 1, 2};
    sort(vi.begin(), vi.end());
    print_vector(vi);
    vector<int> vi2;
    unique_copy(vi.begin(), vi.end(), inserter(vi2, vi2.begin()));
    // print_list(vi2);
    print_vector(vi2);
    return 0;
}