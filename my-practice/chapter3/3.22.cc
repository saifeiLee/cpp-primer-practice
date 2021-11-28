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
    vector<string> text;
    text.push_back("This is first paragraph");
    text.push_back("第一段的另一部分.");
    text.push_back("");
    text.push_back("第二断..");

    for (auto textIter = text.begin();
         textIter != text.end() && !textIter->empty(); ++textIter)
    {
        for (auto strIter = textIter->begin(); strIter != textIter->end(); ++strIter)
        {
            *strIter = toupper(*strIter);
        }
    }
    for (auto textIter = text.cbegin();
         textIter != text.end(); ++textIter)
    {
        cout << *textIter << endl;
    }
    return 0;
}