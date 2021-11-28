
#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::string;

int main()
{
    string str("Hello World!!!");
    decltype(str.size()) punct_cnt = 0;
    for (auto c: str) {
        if (ispunct(c)) {
            punct_cnt++;
        }
    }
    for (auto &c: str)
        c = toupper(c);
    cout << str << endl;
    cout << punct_cnt << " 标点符号" << endl;
    
    unsigned a = -1;
    cout << a << endl;
    return 0;
}