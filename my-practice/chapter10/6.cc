#include <algorithm>
#include <vector>
#include <iostream>
#include <list>
#include <string>

using namespace std;
int main(int argc, char *argv[])
{
    vector<int> vec(10);
    fill_n(vec.begin(), vec.size(), 0);
    for (auto& i: vec) {
        cout << i << endl;
    }
    return 0;
}