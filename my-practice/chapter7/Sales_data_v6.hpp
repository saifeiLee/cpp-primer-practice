#ifndef SALES_DATA_V2_HPP
#define SALES_DATA_V2_HPP

#include <string>
#include <iostream>
using namespace std;

struct Sales_data;

std::istream &read(std::istream &input, Sales_data &transaction);
std::ostream &print(std::ostream &output, const Sales_data &transaction);

struct Sales_data
{
    // 属性
    std::string bookNo;
    unsigned units_sold = 0;
    double revenue = 0.0;

    // 方法
    std::string isbn() const;
    Sales_data &combine(const Sales_data &transaction);

    // 构造函数
    Sales_data() = default;

    explicit Sales_data(const std::string &book_isbn) : bookNo(book_isbn) {}

    Sales_data(const std::string &book_isbn, unsigned units, double price)
        : bookNo(book_isbn), units_sold(units), revenue(units * price) {}

    // Sales_data(std::istream &input);
    Sales_data(std::istream &input)
    {
        read(input, *this);
    }

    // Sales_data(std::istream &input = cin)
    // {
    //     read(input, *this);
    // }
};

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

Sales_data add(const Sales_data &firstTranscation, const Sales_data &secondTranscation)
{
    Sales_data sum = firstTranscation;
    sum.combine(secondTranscation);
    return sum;
}

// Sales_data::Sales_data(std::istream &input)
// {
//     read(input, *this);
// }

#endif