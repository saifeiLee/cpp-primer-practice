#include <algorithm>
#include <vector>
#include <iostream>
#include <list>
#include <string>
#include "../include/print_vec.hpp"
using namespace std;

void elimDups(vector<string> &words)
{
    print_vector(words);
    sort(words.begin(), words.end());
    print_vector(words);
    auto end_unique = unique(words.begin(), words.end());
    cout << "Unique: " << endl;
    print_vector(words);
    words.erase(end_unique, words.end());
    print_vector(words);
}

int main(int argc, char *argv[])
{
    vector<string> vs = {"lsf", "ccx", "ccx", "test"};
    elimDups(vs);
    cout << endl;
    return 0;
}