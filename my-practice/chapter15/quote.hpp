#ifndef QUOTE_HPP
#define QUOTE_HPP

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
    string isbn() const
    {
        return bookNo;
    }
    virtual double net_price(size_t n) const
    {
        cout << "Quote net_price" << endl;
        return n * price;
    }
    virtual ~Quote() = default;
    virtual ostream &debug()
    {
        cout << "bookNo: " << bookNo << " price: " << price;
        return cout;
    }

private:
    string bookNo;

protected:
    double price = 0.0;
};

class Bulk_quote : public Quote
{
public:
    Bulk_quote() = default;
    Bulk_quote(const string &book, double p, size_t qty, double disc)
        : Quote(book, p), min_qty(qty), discount(disc)
    {
    }
    double net_price(size_t n) const override;

private:
    size_t min_qty = 0;
    double discount = 0.0;
};

double Bulk_quote::net_price(size_t cnt) const
{
    if (cnt >= min_qty)
    {
        cout << "Bulk Quote" << endl;
        return cnt * (1 - discount) * price;
    }
    else
        return cnt * price;
}

double print_total(ostream &os, const Quote &item, size_t n)
{
    double ret = item.net_price(n);
    os << "ISBN: " << item.isbn() << " # sold: " << n << " total due: " << ret << endl;
    return ret;
}
#endif