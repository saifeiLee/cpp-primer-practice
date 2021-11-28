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

bool is_shorter(const string& s1, const string &s2) {
    return s1.size() < s2.size();
}

bool compare_sz(const string&s, string::size_type sz) {
    return s.size() >= sz;
}

void biggies(vector<string> &words, vector<string>::size_type sz)
{
    elimDups(words);
    stable_sort(words.begin(), words.end(), is_shorter);
    auto iter = find_if(words.begin(), words.end(), bind(compare_sz, placeholders::_1, sz));
    auto count = words.end() - iter;
    cout << count << "words" << endl;
    for_each(iter, words.end(), [](const string &s)
             { cout << s << " "; });
    cout << endl;
}

int main(int argc, char *argv[])
{
    vector<string> vs = {"Original", "function", "from", "textbook"};
    biggies(vs, 5);
    return 0;
}