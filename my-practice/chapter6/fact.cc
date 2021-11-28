#include <iostream>

using namespace std;

int myFact() {
    cout << "myFact" << endl;
    return 0;
}

bool isShorter(const string &s1, const string &s2) {
    return s1.size() < s2.size();
}