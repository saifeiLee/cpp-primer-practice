#include <algorithm>
#include <vector>
#include <iostream>
#include <list>
#include <string>
#include "../include/print_vec.hpp"

using namespace std;
int main(int argc, char *argv[])
{
    vector<int> vec = {1, 2, 3};
    for (auto iter = vec.crbegin(); iter != vec.crend(); ++iter) {
        cout << *iter << " ";
    }
    cout << endl;
    return 0;
}