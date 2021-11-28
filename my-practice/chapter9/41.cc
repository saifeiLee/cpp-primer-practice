
#include <vector>
#include <iostream>
#include <list>
#include <string>
#include "./helper.hpp"

using namespace std;

int main()
{
    vector<char> vc = {'c', 'h' , 'a', 'r'};
    string s(vc.begin(), vc.end());
    cout << s << endl;
    return 0;
}