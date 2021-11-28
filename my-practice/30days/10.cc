#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
string toBinary(int&);

string toBinary(int &n) {
    // cout << n << endl;
    string bin;
    while (n != 0)
    {
        bin = (n % 2 == 0 ? "0" : "1") + bin;
        n = n / 2;
    }
    return bin;
}

int consOnes(string s) {
    int size = s.length();
    int p = 0, max = 0;
    for (int i = 0; i < size; ++i) {
        if (s.substr(i, 1) == "1") {
            ++p;
            if (p > max) {
                max = p;
            }
        } else {
            p = 0;
        }
    }
    return max;
}

int main()
{
    string n_temp;
    getline(cin, n_temp);

    int n = stoi(ltrim(rtrim(n_temp)));
    string res = toBinary(n);
    cout << consOnes(res) << endl;
    return 0;
}

string ltrim(const string &str)
{
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace))));

    return s;
}

string rtrim(const string &str)
{
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end());

    return s;
}
