#include <memory>
#include <iostream>
#include <string>
#include <vector>
#include <fstream>

using namespace std;

class ShorterString
{
public:
    bool operator()(const string &lhs, const string &rhs) const
    {
        return lhs.size() < rhs.size();
    }
};

class StringEqual
{
public:
    StringEqual(size_t len) : length_(len) {}
    bool operator()(const string &s) const
    {
        // cout << "length: " << length_ << endl;
        // cout << "input str: " << s << " " << s.size() << endl;
        return s.size() == length_;
    }

private:
    size_t length_;
};

int main(int argc, char *argv[])
{
    for (size_t i = 1; i < 21; ++i)
    {
        ifstream ifs("./test.txt");
        if (!ifs)
        {
            cerr << "open file error" << endl;
            return -1;
        }
        istream_iterator<string> beg(ifs), end;
        cout << "Length:" << i << " " << count_if(beg, end, StringEqual(i)) << endl;
    }
    return 0;
}
