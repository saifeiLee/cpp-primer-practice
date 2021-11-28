#include <algorithm>
#include <vector>
#include <iostream>
#include <list>
#include <string>
#include "../include/print_vec.hpp"

using namespace std;
int main(int argc, char *argv[])
{
    list<int> list_a = {1, 2, 3, 0, 2, 0};
    auto target = find(list_a.crbegin(), list_a.crend(), 0);
    cout << *target << endl;
    list<int> result(list_a.cbegin(), target.base());

    return 0;
}