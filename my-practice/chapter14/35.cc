#include <memory>
#include <iostream>
#include <string>
#include <vector>
#include <fstream>

using namespace std;

class PrintString
{
public:
    string operator()(istream &in)
    {
        string s;
        in >> s;
        if (in)
        {
            return s;
        }
        cout << "Error: input error" << endl;
        return s;
    }
};

int main()
{
    PrintString in;
    string s = in(cin);
    cout << s << endl;
    return 0;
}