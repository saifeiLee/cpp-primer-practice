#include "./quote.hpp"

using namespace std;

class Disc_quote : public Quote
{
public:
    Disc_quote(const string &book = "", double sales_price = 0.0, size_t qty = 0, double disc = 0.0) : Quote(book, sales_price), quantity(qty), discount(disc) {}

protected:
    size_t quantity;
    double discount;
};

class Bulk_quote : public Disc_quote
{
public:
    Bulk_quote(const string &book = "", double sales_price = 0, size_t qty = 0, double dis_rate = 0) : Disc_quote(book, sales_price, qty, dis_rate) {}

    double net_price(size_t cnt) const
    {
        if (cnt > quantity)
        {
            return cnt * (1 - discount) * price;
        }
        else
        {
            return cnt * price;
        }
    }
};

int main()
{
}
