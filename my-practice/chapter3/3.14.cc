#include <iostream>
#include <vector>

using std::cout;
using std::cin;
using std::vector;

int main() {
    cout << "输入数字:";
    int userInput;
    vector<int> collectedData;
    while (cin >> userInput)
    {
        collectedData.push_back(userInput);
    }
    return 0;
}