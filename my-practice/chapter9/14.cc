#include <iostream>
#include <vector>
#include <string>
#include <list>

using namespace std;

int main()
{
    list<const char *> str = {"123", "lsf"};
    vector<string> vs;
    vs.assign(str.cbegin(), str.cend());

    for (auto &s : vs)
    {
        cout << s << endl;
    }
    return 0;
}