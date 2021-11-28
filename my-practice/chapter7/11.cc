#include <iostream>
#include "./Sales_data_v4.hpp"

using std::cin;
using std::cout;
using std::endl;

int main()
{
    Sales_data first_transaction;
    Sales_data second_transcation("xxx");
    Sales_data third_transcation("xxx", 5, 1.5);
    Sales_data fourth_transcation(cin);

    cout << "输入sale data: isbn, units, sold, price each: " << endl;

    print(cout, first_transaction);
    cout << endl;
    print(cout, second_transcation);
    cout << endl;
    print(cout, third_transcation);
    cout << endl;
    print(cout, fourth_transcation);
    cout << endl;

    return 0;
}