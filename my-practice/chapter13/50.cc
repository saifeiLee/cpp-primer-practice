#include <memory>
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include "./String.hpp"
using namespace std;


int main()
{
    String s("123");
    cout << s << endl;
    s.push_back('s');
    s.push_back('s');
    s.push_back('s');
    vector<String> v;
    v.push_back(s);
    v.push_back(s);
    v.push_back(s);
    s = "456";
    return 0;
}