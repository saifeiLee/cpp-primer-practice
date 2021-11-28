
#include <vector>
#include <iostream>
#include <list>
#include <string>
#include "./helper.hpp"
#include <fstream>

using namespace std;

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        cerr << "要求有两个参数" << endl;
        return -1;
    }

    ifstream ifs(argv[argc - 1]);
    if (!ifs)
    {
        cerr << "File is not valid, cannot open." << endl;
        return -1;
    }
    string word;
    string ascender("bdfhkltBDFHT");
    string descender("gjpqyGPY");
    string result;
    while (ifs >> word)
    {
        if (word.find_first_of(ascender) == string::npos && word.find_first_of(descender) == string::npos)
        {
            if (word.size() > result.size())
            {
                result = word;
            }
        }
    }
    cout << result << endl;
    return 0;
}