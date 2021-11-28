#include <iostream>
#include "./Sales_data_v5.hpp"

using std::cin;
using std::cout;
using std::endl;

int main()
{
    while (cin)
    {
        // 使用static，让每次while循环都复用该历史值
        static Sales_data total(cin);
        if (total.isbn().empty())
        {
            cout << "没有数据" << endl;
            return -1;
        }
        Sales_data trans(cin);
        if (total.isbn() == trans.isbn())
        {
            total.combine(trans);
        }
        else
        {
            print(cout, total) << endl;
        }
    }
    return 0;
}