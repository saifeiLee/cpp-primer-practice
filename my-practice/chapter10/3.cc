#include <algorithm>
#include <vector>
#include <iostream>
#include <list>
#include <string>
#include <numeric>

using namespace std;
int main(int argc, char *argv[])
{
    vector<int>vci = {1, 2, 3};
    const int sum = accumulate(vci.begin(), vci.end(), 0);
    vector<string> vs = {"123", "lsf"};
    string sum = accumulate(vci.begin(), vci.end(), string(""));
    cout << sum << endl;
    return 0;
}