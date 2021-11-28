
#include <vector>
#include <iostream>
#include <list>
#include <string>
#include "./helper.hpp"

using namespace std;

int main()
{
    vector<int> vi;
    auto val = vi.at(0);
    auto val2 = vi[0];
    auto val3 = vi.front();
    auto val4 = vi.begin();
    cout << val << endl;
    cout << val2 << endl;
    cout << val3 << endl;
    cout << *val4 << endl;
    return 0;
}