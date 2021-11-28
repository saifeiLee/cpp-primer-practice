#include <fstream>
#include <iostream>
#include <string>
using namespace std;

int main() {
    string file_name = "template.cc";
    ifstream input(file_name);
    if (input) {
        string word;
        int count = 0;
        while (input >> word)
        {
            ++count;
            if (count == 3) {
                return 0;
            }
            cout << word;
        }
    }
    return 0;
}