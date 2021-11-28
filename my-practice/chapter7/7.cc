#include <iostream>
#include <string>
#include "./Sales_data_v3.hpp"

using std::cin;
using std::cout;
using std::endl;
using std::string;

int main()
{
    Sales_data total;
    if (read(cin, total))
    {
        Sales_data transaction;
        while (read(cin, transaction))
        {
            if (total.isbn() == transaction.isbn())
            {
                total.combine(transaction);
            }
            else
            {
                print(cout, total);
                cout << endl;
                total = transaction;
            }
        }
        print(cout, total);
        cout << endl;
    }
    else
    {
        std::cerr << "No data?" << endl;
        return -1;
    }
    return 0;
}