#include <stack>
#include <vector>
#include <iostream>
#include <list>
#include <string>
#include "./helper.hpp"

using namespace std;

int main()
{
    string s = "(((1+2)+3)+4)";
    stack<char> sc;
    int temp = 0;
    for (const auto&c: s) {
        if (c != ')') {
            sc.push(c);
        } else {
            while (sc.top() != '(')
            {
                if (isdigit(sc.top()))
                    temp += (sc.top() - 48);
                sc.pop();
            }
            sc.pop();
        }
    }
    cout << temp << endl;
    return 0;
}