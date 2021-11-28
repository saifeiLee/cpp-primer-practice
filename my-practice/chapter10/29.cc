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
    ifstream ifs(argv[1]);
    istream_iterator<string> ifs_iter(ifs), eof;
    vector<string> vs(ifs_iter, eof);
    for (const auto &s : vs)
    {
        cout << s << " ";
    }
    cout << endl;
    return 0;
}