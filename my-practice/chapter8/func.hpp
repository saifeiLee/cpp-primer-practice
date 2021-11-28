#include <iostream>

using namespace std;

extern istream &input(istream &is)
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