#include <algorithm>
#include <vector>
#include <iostream>
#include <list>
#include <string>
#include "../include/print_vec.hpp"
#include "../include/Sales_data_v8.hpp"

using namespace std;
bool compareIsbn(Sales_data &s1, Sales_data &s2)
{
    return s1.isbn() < s2.isbn();
}

int main(int argc, char *argv[])
{
}