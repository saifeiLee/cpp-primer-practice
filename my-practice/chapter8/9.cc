#include <iostream>
#include <sstream>
// #include "./func.hpp"
using namespace std;

extern istream &input(istream &is);

int main() {
    string s = "hello w";
    istringstream is(s);
    input(is);
    return 0;
}