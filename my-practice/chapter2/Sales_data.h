#ifndef SALES_DATA_H
#define SALES_DATA_H
#include <string>;

struct Sales_Data
{
    std::string bookNo = "s";
    unsigned int units_sold = 0;
    double price = 0.0;
    double revenue = 0.0;
};
#endif