#include <algorithm>
#include <vector>
#include <iostream>
#include <list>
#include <string>
#include <numeric>

using namespace std;
int main(int argc, char *argv[])
{
    string s;
    list<string> ls;
    while (cin >> s)
    {
        ls.push_back(s);
    }
    cout << "Specify a string: " << endl;
    cin.clear();
    cin >> s;
    cout << "There are " << count(ls.begin(), ls.end(), s) << " count of " << s << endl;
    return 0;
}