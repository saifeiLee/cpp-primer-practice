#include <memory>
#include <iostream>
#include <string>
#include <vector>

using namespace std;
vector<int> *new_vector()
{
    return new vector<int>;
}

void read_vector(vector<int> *vi)
{
    int i;
    while (cin >> i)
    {
        vi->push_back(i);
    }
}

void print_vector(vector<int> *vi)
{
    for (const auto &i : *vi)
    {
        cout << i << endl;
    }
}

int main()
{
    auto *p = new_vector();
    read_vector(p);
    print_vector(p);
    delete p;   // 记得自己删除动态指针
    return 0;
}