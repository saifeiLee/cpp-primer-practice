
#include <vector>
#include <iostream>
#include <list>
#include <string>
#include "./helper.hpp"

using namespace std;
unsigned month_transform(const string &);

struct Date
{
    void print()
    {
        cout << year << " " << month << " " << day << endl;
    }

private:
    unsigned year;
    unsigned month;
    unsigned day;

public:
    Date(const string &s)
    {
        // January 1, 1900
        string type1_symbol = ",";
        // 1/1/1990
        string type2_symbol = "/";
        // Jan 1 1990
        string type3_symbol = " ";

        string::size_type index = 0;
        const string numbers("1234567890");
        if ((index = s.find(type1_symbol)) != string::npos)
        {
            // 命中第一种格式
            // 先找到表示 “天”的数字
            auto first_number = s.find_first_of(numbers);
            day = stoi(s.substr(first_number, index - first_number));
            string m = s.substr(0, first_number - 1);
            month = month_transform(m);
            auto second_number = s.find_first_of(numbers, first_number + 1);
            year = stoi(s.substr(second_number));
        }
        else if ((index = s.find(type2_symbol)) != string::npos)
        {
            auto first_number = s.find_first_of(numbers);
            day = stoi(s.substr(first_number, index - first_number));
            auto second_number = s.find_first_of(numbers, first_number + 1);
            index = s.find(type2_symbol, first_number + 1);
            month = stoi(s.substr(second_number, index - second_number));
            auto third_number = s.find_first_of(numbers, second_number + 1);
            year = stoi(s.substr(third_number));
        }
        else if ((index = s.find(type3_symbol)) != string::npos)
        {

            // day = stoi(s.substr(first_number, ))
            string m = s.substr(0, index);
            month = month_transform(m);
            auto first_number = s.find_first_of(numbers);
            index = s.find(type3_symbol, first_number);
            day = stoi(s.substr(first_number, index - first_number));
            auto second_number = s.find_first_of(numbers, index + 1);
            year = stoi(s.substr(second_number));
        }
        else
        {
            throw runtime_error("Invalid argument " + s);
        }
    }
};

unsigned month_transform(const string &s)
{
    if (s == "January" || s == "Jan")
        return 1;
    else if (s == "February" || s == "Feb")
        return 2;
    else if (s == "March" || s == "Mar")
        return 3;
    else if (s == "April" || s == "Apr")
        return 4;
    else if (s == "May" || s == "May")
        return 5;
    else if (s == "June" || s == "Jun")
        return 6;
    else if (s == "July" || s == "Jul")
        return 7;
    else if (s == "August" || s == "Aug")
        return 8;
    else if (s == "September" || s == "Sep")
        return 9;
    else if (s == "October" || s == "Oct")
        return 10;
    else if (s == "November" || s == "Nov")
        return 11;
    else if (s == "December" || s == "Dec")
        return 12;
    else
        throw runtime_error("Invalid argument " + s);
}

int main()
{
    string s1 = "January 2, 1990";
    string s2 = "1/2/1990";
    string s3 = "Jan 2 1990";
    Date date1(s1);
    Date date2(s2);
    Date date3(s3);
    date1.print();
    date2.print();
    date3.print();
    return 0;
}