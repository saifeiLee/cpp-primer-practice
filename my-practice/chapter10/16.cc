#include <algorithm>
#include <vector>
#include <iostream>
#include <list>
#include <string>

using namespace std;

void elimDups(vector<string> &words)
{
    sort(words.begin(), words.end());
    auto end_unique = unique(words.begin(), words.end());
    words.erase(end_unique, words.end());
}

void biggies(vector<string> &words, vector<string>::size_type sz)
{
    elimDups(words);
    stable_sort(words.begin(), words.end(), [](const string &a, const string &b)
                { return a.size() < b.size(); });
    auto wc = find_if(words.begin(), words.end(), [sz](const string &s)
                      { return s.size() >= sz; });
    auto count = words.end() - wc;
    cout << count << "words" << endl;
    for_each(wc, words.end(), [](const string &s)
             { cout << s << " "; });
    cout << endl;
}

int main(int argc, char *argv[])
{
    vector<string> vs = {"Original", "function", "from", "textbook"};
    biggies(vs, 5);
    return 0;
}