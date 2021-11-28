#include <iostream>

using namespace std;

istream &input(istream &is)
{
    char c;
    while (!is.eof())
    {
        /* code */
        is >> c;
        cout << c << endl;
    }
    is.clear();
    return is;
}

// int main()
// {
//     // input(cin);
//     cout << unitbuf;
//     cout << 123;
//     cout << 456;
//     cout << 7;
//     return 0;
// }