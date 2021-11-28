#include <algorithm>
#include <vector>
#include <iostream>
#include <list>
#include <string>

using namespace std;

int main(int argc, char *argv[])
{
    auto sum2 = [](int i, int j) {
        return i + j;
    };
    const int result = sum2(1, 2);
    cout << result << endl;
    return 0;
}