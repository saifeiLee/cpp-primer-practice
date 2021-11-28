#ifndef SALES_DATA_V2_HPP
#define SALES_DATA_V2_HPP

#include <string>
#include <istream>
struct Sales_data
{
    std::string bookNo;
    unsigned units_sold = 0;
    double revenue = 0.0;
    std::string isbn() const;
    Sales_data &combine(const Sales_data &transaction);
};

std::istream &read(std::istream &input, Sales_data &transaction);
std::ostream &print(std::ostream &output, const Sales_data &transaction);

std::string Sales_data::isbn() const
{
    return this->bookNo;
}

Sales_data &Sales_data::combine(const Sales_data &transaction)
{
    if (this->isbn() == transaction.isbn())
    {
        this->units_sold += transaction.units_sold;
        this->revenue += transaction.revenue;
    }
    return *this;
}

std::istream &read(std::istream &input, Sales_data &transaction)
{
    double price = 0.0;
    input >> transaction.bookNo >> transaction.units_sold >> price;
    transaction.revenue = transaction.units_sold * price;
    return input;
}

std::ostream &print(std::ostream &output, const Sales_data &transaction)
{
    output << transaction.isbn() << " " << transaction.units_sold << " " << transaction.revenue;
    return output;
}

#endif