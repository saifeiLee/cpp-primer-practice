#include <iostream>
#include <string>
using std::cin;
using std::cout;
using std::endl;
using std::string;

int main() {
    cout << "输入两个字符串用于对比:" << endl;
    string firstStr;
    string secondStr;
    if (cin >> firstStr >> secondStr) {
        auto firstStrSize = firstStr.size();
        auto secondStrSize = secondStr.size();
        if (firstStr == secondStr) {
            cout << "一样长." << endl;
        } else {
            string result = "更长";
            if (firstStrSize < secondStrSize) {
                result = "更短";
            }
            cout << "'" << firstStr << "' is" << result << " than " << secondStr << endl;
        }
    } else {
        std::cerr << "Wrong" << endl;
    }

    return 0;
}