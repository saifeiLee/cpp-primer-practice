#include <fstream>
#include <sstream>
#include <vector>
#include <iostream>
using namespace std;

int main(int argc, char *argv[])
{
    vector<string> vs;
    if (argc != 2)
    {
        cerr << "参数个数要是2个, 当前" << argc << "个" << endl;
        return -1;
    }
    ifstream input;
    input.open(argv[argc - 1]);
    if (input)
    {
        string line;
        while (getline(input, line))
        {
            vs.push_back(line);
        }
    }
    input.close();
    for (auto &line : vs)
    {
        istringstream in(line);
        string word;
        while (in >> word)
        {
            cout << word << endl;
        }
    }
    return 0;
}

int answer_2(int argc, char* argv[]) {
    ifstream ifs(argv[argc - 1]);
    string s, w;
    vector<string> vs;
    while (getline(ifs, s))
    {
        vs.push_back(s);
    }
    istringstream ist;
    for(const auto& str_line: vs) {
        ist.str(str_line);
        while (ist >> w)
        {
            cout << w << endl;
        }
        ist.clear();
    }
}