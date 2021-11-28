#include <iostream>

struct Sales_Data
{
    std::string bookNo = "s";
    unsigned int units_sold = 0;
    double revenue = 0.0;
};

using namespace std;

int main()
{
    Sales_Data sale1, sale2;
    double price = 0;
    cin >> sale1.bookNo >> sale1.units_sold >> price;
    sale1.revenue = sale1.units_sold * price;

    cin >> sale2.bookNo >> sale2.units_sold >> price;
    sale2.revenue = sale2.units_sold * price;
    if (sale1.bookNo == sale2.bookNo)
    {
        unsigned totalCnt = sale1.units_sold + sale2.units_sold;
        double totalRevenue = sale1.revenue + sale2.revenue;
        cout << sale1.bookNo << " " << totalCnt << " " << totalRevenue << " ";
        if (totalCnt != 0)
        {
            cout << totalRevenue / totalCnt << endl;
        }
        return 0;
    }
    else
    {
        cerr << "Data must same in ISBN." << endl;
        return -1;
    }
    return 0;
}