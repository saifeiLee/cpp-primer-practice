#include <iostream>
#include <string>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;

int main()
{
    cout << "输入10个数字：" << endl;
    vector<int> userInput(10);
    for (auto iter = userInput.begin(); iter != userInput.end(); ++iter) {
        cin >> *iter;
    }

    for (auto iter = userInput.begin(); iter != userInput.end(); ++iter) {
        *iter = 2 * (*iter);
    }

    // print
     for (auto iter = userInput.begin(); iter != userInput.end(); ++iter) {
         cout << *iter << endl;
    }
    return 0;
}