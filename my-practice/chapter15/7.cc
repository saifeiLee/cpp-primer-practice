#include <iostream>
#include <string>
using namespace std;
class Quote
{
public:
    Quote() = default;
    Quote(const string &book, double sales_price)
        : bookNo(book), price(sales_price)
    {
    }
    string isbn() const;
    virtual double net_price(size_t n) const
    {
        return n * price;
    }
    virtual ~Quote() = default;

private:
    string bookNo;

protected:
    double price = 0.0;
};

class Spe_Quote : public Quote
{
public:
    Spe_Quote(const string &bookNo, double price, size_t limit, double dis) : Quote(bookNo, price), limit(limit), discount(dis) {}
    double net_price(size_t n) const override;

private:
    size_t limit = 0;
    double discount = 0.0;
};

double Spe_Quote::net_price(size_t n) const
{
    if (n <= limit)
    {
        return (1 - discount) * price * n;
    }
    else
    {
        return price * n;
    }
}

int main()
{
    // const string bookNo("123");
    Spe_Quote q("test", 1.1, 3, 0.75);
    double net_price = q.net_price(5);
    double net_price2 = q.net_price(2);
    cout << net_price << " " << net_price2 << endl;
    return 0;
}