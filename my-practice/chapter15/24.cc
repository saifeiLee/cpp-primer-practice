#include "./quote.hpp"
#include <iostream>
#include <vector>
#include <memory>

using namespace std;

int main()
{
    vector<shared_ptr<Quote>> itemVec;
    for (size_t i = 0; i != 10; ++i)
    {
        Bulk_quote item("C++ Primer", 6, 5, 0.4);
        itemVec.push_back(make_shared<Bulk_quote>(item));
    }

    double sum = 0;
    for (vector<shared_ptr<Quote>>::iterator iter = itemVec.begin(); iter != itemVec.end(); ++iter)
    {
        sum += iter->get()->net_price(10);
    }
    cout << sum << endl;
    return 0;
}