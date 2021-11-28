#include <memory>
#include <iostream>
#include <string>
#include <vector>

using namespace std;
shared_ptr<vector<int>> new_vector()
{
    return make_shared<vector<int>>();
}

void read_vector(shared_ptr<vector<int>> vi)
{
    int i;
    while (cin >> i)
    {
        vi->push_back(i);
    }
}

void print_vector(shared_ptr<vector<int>> vi)
{
    for (const auto &i : *vi)
    {
        cout << i << endl;
    }
}

int main()
{
    auto p = new_vector();
    read_vector(p);
    print_vector(p);
    return 0;
}