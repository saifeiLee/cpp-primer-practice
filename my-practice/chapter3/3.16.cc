#include <iostream>
#include <string>
#include <vector>


using std::cout;
using std::cin;
using std::string;
using std::vector;

int main() {
    vector<string> v7{10, "hi"};
    for(auto str: v7) {
        cout << str << std::endl;
    }
    return 0;
}