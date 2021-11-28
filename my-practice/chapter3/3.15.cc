#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::vector;
using std::string;

int main()
{
    cout << "输入数字:";
    string userInput = "";
    vector<string> collectedData;
    while (cin >> userInput)
    {
        collectedData.push_back(userInput);
    }
    return 0;
}