
#include <vector>
#include <iostream>
#include <list>
#include <string>
#include "./helper.hpp"

using namespace std;

int main()
{
    list<int> i_lst = {1, 2};
    i_lst.insert(i_lst.begin(), 0);
    for (const auto& i: i_lst) {
        cout << i << " ";
    }
    cout << endl;
    return 0;
}