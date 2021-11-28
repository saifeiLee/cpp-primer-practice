#include <memory>
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include "./StrVec.hpp"
using namespace std;

class String
{
public:
    String(const char *str = "")
    {
        if (str)
        {
            len = strlen(str);
            pstr = new char[len + 1];
            strcpy(pstr, str);
        }
        else
        {
            len = 0;
            pstr = new char[1];
            pstr[0] = '\0';
        }
    }

    String(const String &rhs)
    {
        len = rhs.len;
        pstr = new char[len + 1];
        strcpy(pstr, rhs.pstr);
    }
    ~String()
    {
        delete[] pstr;
    }
    size_t size() const
    {
        return len;
    }

private:
    int len;
    char *pstr;
};

int main()
{
    // StrVec s({"hello", "world"});
    StrVec s;
    cout << s.size() << endl;
    s.push_back("hello");
    s.push_back("1");
    s.push_back("2");
    cout << s << endl;
    return 0;
}