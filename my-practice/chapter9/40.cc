
#include <vector>
#include <iostream>
#include <list>
#include <string>
#include "./helper.hpp"

using namespace std;

int main()
{
    int size = 1000;
    vector<string> svec;
    svec.reserve(1024);
    string word;
    while (size-- > 0)
    {
        svec.push_back("test");
    }
    svec.resize(svec.size() + svec.size() / 2);
    cout << "Capacity: " << svec.capacity() << endl;
    return 0;
}