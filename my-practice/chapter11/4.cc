#include <algorithm>
#include <vector>
#include <iostream>
#include <list>
#include <string>
#include <map>
#include <set>
#include "../include/print_vec.hpp"

using namespace std;
int main(int argc, char *argv[])
{
    string word;
    map<string, size_t> word_count;
    set<string> exclude = {
        {"The", "But", "And", "Or", "An"}};
    while (cin >> word)
    {
        if (exclude.find(word) == exclude.end())
        {
            auto first = word.begin();
            auto end = word.end();
            while (first != end)
            {
                if (isupper(*first))
                {
                    *first = tolower(*first);
                }
                ++first; // 遍历
            }
            if (ispunct(*(--end)))
            {
                word.pop_back();
            }
            ++word_count[word];
        }
    }

    for (const auto &w : word_count)
    {
        cout << w.first << " occurs " << w.second << "times" << endl;
    }
    return 0;
}