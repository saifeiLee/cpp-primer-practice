#include <algorithm>
#include <vector>
#include <iostream>
#include <list>
#include <string>
#include "../include/print_vec.hpp"

using namespace std;
bool isShorter(const string &s1, const string &s2)
{
    return s1.size() < s2.size();
}

void elimDups(vector<string> &words)
{
    // print_vector(words);
    sort(words.begin(), words.end());
    // print_vector(words);
    auto end_unique = unique(words.begin(), words.end());
    words.erase(end_unique, words.end());
    // print_vector(words)
}

int main(int argc, char *argv[])
{
    vector<string> vs =
        {"the", "time", "is", "near1", "near2", "the", "great", "sunrise"};
    elimDups(vs);
    stable_sort(vs.begin(), vs.end(), isShorter);
    print_vector(vs);
    return 0;
}