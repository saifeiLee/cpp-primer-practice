#include <iostream>

using namespace std;

int odd[] = {1, 3, 5};
int even[] = {2, 4, 6};

decltype(odd) &return_odd(int i)
{
    return i % 2 ? odd : even;
}

const string &shorterString(const string &s1, const string &s2)
{
    return s1.size() <= s2.size() ? s1 : s2;
}

string &shorterString(string &s1, string &s2)
{
    auto &r = shorterString(const_cast<const string &>(s1), const_cast<const string &>(s2));
    return const_cast<string &>(r);
}

int main()
{
    int(&ptr)[3] = return_odd(1);
    cout << *ptr << endl;
    return 0;
}