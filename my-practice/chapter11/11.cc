#include <algorithm>
#include <vector>
#include <iostream>
#include <list>
#include <string>
#include <map>
#include <set>
#include "../include/print_vec.hpp"
#include "../include/Sales_data_v8.hpp"

using namespace std;

bool compareIsbn(const Sales_data &s1, const Sales_data &s2)
{
    return s1.isbn() < s2.isbn();
}

multiset<Sales_data, decltype(compareIsbn) *> bookstore(compareIsbn);
// multiset<Sales_data, bool (*)(const Sales_data &, const Sales_data &)> bookstore(compareIsbn);
int main(int argc, char *argv[])
{
    return 0;
}