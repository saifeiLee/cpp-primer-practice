#include <algorithm>
#include <vector>
#include <iostream>
#include <list>
#include <string>
#include "../include/print_vec.hpp"

using namespace std;

int main(int argc, char *argv[])
{
    list<int> lst1 = {1, 2, 3, 4};
    list<int> lst2, lst3;
    copy(lst1.cbegin(),lst1.cend(), front_inserter(lst2));
    print_list(lst2);
    copy(lst1.cbegin(), lst1.cend(), inserter(lst3, lst3.begin()));
    print_list(lst3);
    return 0;
}