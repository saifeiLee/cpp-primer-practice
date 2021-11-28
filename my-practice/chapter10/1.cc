#include <algorithm>
#include <vector>
#include <iostream>
#include <list>
#include <string>

using namespace std;

int main()
{
    vector<int>vci = {1, 2, 3, 2, 3, 2};
    auto cnt = count(vci.begin(), vci.end(), 2);
    cout << cnt << endl;
    return 0;
}