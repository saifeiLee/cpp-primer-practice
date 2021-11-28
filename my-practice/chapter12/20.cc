#include <memory>
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include "../include/StrBlob.hpp"

using namespace std;
int main(int argc, char *argv[])
{
    if (argc != 2)
        return -1;
    ifstream ifs(argv[1]);
    if (!ifs)
        return -1;
    string s;
    StrBlob b1;
    while (getline(ifs, s))
    {
        b1.push_back(s);
    }
    ifs.close();
    StrBlobPtr beg = b1.begin();
    for (auto count = b1.size(); count > 0; --count)
    {
        cout << beg.deref() << endl;
        beg.incr();
    }
    return 0;
}