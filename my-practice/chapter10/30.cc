#include <algorithm>
#include <vector>
#include <iostream>
#include <list>
#include <string>
#include "../include/print_vec.hpp"
#include "../include/Sales_data_v8.hpp"
#include <fstream>
using namespace std;
int main(int argc, char *argv[])
{
    istream_iterator<int> iter(cin), eof;
    ostream_iterator<int> oter(cout, "\n");
    vector<int> vec;
    copy(iter, eof, back_inserter(vec));
    sort(vec.begin(), vec.end());
    unique_copy(vec.cbegin(), vec.cend(), oter);
    return 0;

    // istream_iterator<int> in_iter(cin), eof;
    // ostream_iterator<int> out_iter(cout, "\n");
    // vector<int> vi;
    // copy(in_iter, eof, back_inserter(vi));
    // sort(vi.begin(), vi.end());
    // unique_copy(vi.begin(), vi.end(), out_iter);
}
