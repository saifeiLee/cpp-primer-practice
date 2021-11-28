
#include <vector>
#include <iostream>
#include <list>
#include <string>
#include "./helper.hpp"

using namespace std;

int main()
{
    vector<int> vec_i = {1, 2, 3};
    cout << vec_i.size() << endl;

    vec_i.resize(100);
    cout << vec_i.size() << endl;
    for (auto &i : vec_i)
    {
        cout << i << " ";
    }
    cout << endl;
    vec_i.resize(1);
    for (auto &i : vec_i)
    {
        cout << i << " ";
    }

    cout << endl;
    return 0;
}