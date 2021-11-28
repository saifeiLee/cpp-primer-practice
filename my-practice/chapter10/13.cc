#include <algorithm>
#include <vector>
#include <iostream>
#include <list>
#include <string>

using namespace std;

bool greater_than_5(const string &s)
{
    return s.size() > 5;
}

int main(int argc, char *argv[])
{
    vector<string> vs =
        {"hello", "world", "is", "everything", "all", "right"};
    auto iter = partition(vs.begin(), vs.end(), greater_than_5);
    for (auto bg = vs.begin(); bg != iter; ++bg) {
        cout << *bg << " ";
    }
    cout << endl;
    return 0;
}