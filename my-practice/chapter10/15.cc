#include <algorithm>
#include <vector>
#include <iostream>
#include <list>
#include <string>

using namespace std;
int main(int argc, char *argv[])
{
    int i = 10;
    auto sum2 = [i]( int j) {
        return i + j;
    };
    auto res = sum2(10);
    cout << res << endl;
    return 0;
}