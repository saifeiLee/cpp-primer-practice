#include <algorithm>
#include <vector>
#include <iostream>
#include <list>
#include <string>
#include <fstream>
#include "../include/print_vec.hpp"
#include "../include/Sales_data_v8.hpp"

using namespace std;

int main(int argc, char *argv[])
{
    string input_file(argv[1]);
    string out_file_1(argv[2]);
    string out_file_2(argv[3]);
    ifstream ifs_i(input_file);
    ofstream os_odd(out_file_1);
    ofstream os_even(out_file_2);
    istream_iterator<int> in_iter(ifs_i), eof;
    ostream_iterator<int> out_iter_odd(os_odd, " "), out_iter_even(os_even, "\n");
    while (in_iter != eof)
    {
        /* code */
        (*in_iter % 2 == 0) ? out_iter_odd = *in_iter : out_iter_even = *in_iter;
        ++in_iter;
    }
    return 0;
}