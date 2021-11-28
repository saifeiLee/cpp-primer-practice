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
    string userInput;
    vector<string> wordList;
    while (cin >> userInput)
    {
        wordList.push_back(userInput);
    }
    for (auto &str : wordList)
    {
        for (auto &c : str)
        {
            c = toupper(c);
        }
    }
    cout << "转后：" << endl;
    for (auto str : wordList)
    {
        cout << str << endl;
    }

    return 0;
}