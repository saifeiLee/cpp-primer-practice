#include "./quote.hpp"
#include <iostream>
#include <vector>

using namespace std;

int main()
{
    vector<Quote> itemVec;
    for (size_t i = 0; i != 10; ++i)
    {
        Bulk_quote item("C++ Primer", 6, 5, 0.4);
        itemVec.push_back(item);
    }

    double sum = 0;
    for (vector<Quote>::iterator iter = itemVec.begin(); iter != itemVec.end(); ++iter)
    {
        sum += iter->net_price(10);
    }
    cout << sum << endl;
    return 0;
}