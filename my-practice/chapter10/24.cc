#include <algorithm>
#include <vector>
#include <iostream>
#include <list>
#include <string>
#include <functional>

using namespace std;
bool check_size(const string &s, string::size_type sz)
{
    cout << s << " & " << sz << endl;
    // cout <<(s.size() >= sz) << endl;
    return s.size() > sz;
}

int main(int argc, char *argv[])
{
    vector<int> vi = {222, 12, 3, 10, 5, 6};
    // vector<int> vi = {5, 6, 7};
    string s("wewewe");
    auto iter = find_if(vi.begin(), vi.end(), bind(check_size, s, placeholders::_1));
    // auto iter = stable_partition(vi.begin(), vi.end(), bind(check_size, s, placeholders::_1));
    if (iter == vi.end()) {
        cout << "No found" << endl;
    } else {
        cout << *iter << endl;
        // cout << *(iter + 1) << endl;
    }
    return 0;
}