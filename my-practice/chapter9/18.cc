#include <deque>
#include <vector>
#include <iostream>
#include <list>
#include <string>

using namespace std;

template <typename T>

void print_vector(vector<T> vs)
{
    for (const auto &s : vs)
    {
        cout << s << " ";
    }
    cout << " ";
}

void read_and_print_string_by_deque()
{
    string str;
    deque<string> ds;
    while (cin >> str)
    {
        /* code */
        ds.push_back(str);
    }
    deque<string>::iterator bit = ds.begin(), eit = ds.end();
    while (bit != eit)
    {
        cout << *bit << " ";
        ++bit;
    }

    cout << endl;
}

int main()
{
    read_and_print_string_by_deque();
    return 0;
}