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

}
