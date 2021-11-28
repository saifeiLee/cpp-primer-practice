#include "../include/Sales_data_v8.hpp"
#include <fstream>
#include <iostream>

using namespace std;

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        cerr << "Incorrect command-line args"
             << " Need 2 now " << argc << endl;
        return -1;
    }

    ifstream input(argv[argc - 1]);
    Sales_data total;
    if (read(input, total)) {
        Sales_data trans;
        while (read(input, trans))
        {
            if(total.isbn() == trans.isbn()) {
                total.combine(trans);
            } else {
                print(cout, total) << endl;
                total = trans;
            }
        }
        print(cout, total) << endl;
    } else {
        cerr << "No data?" << endl;
    }
    return 0;
}