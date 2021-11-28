#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

int main(int argc, char *argv[])
{
    vector<string> vs;
    string str;
    ifstream ifs;
    ifs.open(argv[argc - 1]);
    if (ifs) {
        while(getline(ifs, str))
            vs.push_back(str);
    } else {
        cerr << "Cannot open "  << string(argv[argc - 1]) << endl;
    }

    for (auto &s: vs) {
        cout << s << endl;
    }
    return 0;
}