#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
using namespace std;

struct PersonInfo
{
    string name;
    vector<string> phones;
};


int main(int argc, char* argv[]) {
  if (argc != 2)
    {
        cerr << "参数个数要是2个, 当前" << argc << "个" << endl;
        return -1;
    }
    ifstream ifs(argv[argc - 1]);
    if (!ifs) {
        cerr << "Invalid arg " << argv[argc - 1] << endl;
        return -1;
    }
    string line, word;
    vector<PersonInfo> people;
    istringstream record;
    while (getline(ifs, line))
    {
        PersonInfo info;
        record.str(line);   // 将line拷贝到record流中
        record >> info.name;
        while (record >> word)
        {
            info.phones.push_back(word);
        }
        people.push_back(info);
        record.clear();
    }
    for(const auto& entry: people) {
        ostringstream formatted, badNums;
        for (const auto& nums: entry.phones) {
            // 省略
        }
    }
    return 0;
}