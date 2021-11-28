#include <iostream>
#include <vector>
#include <list>

using namespace std;

void test(vector<int> vi)
{
    vi.push_back(123);
}
void print_vi(vector<int> vi)
{
    for (const auto &i : vi)
    {
        cout << i << " ";
    }
    cout << endl;
}

int main()
{
    vector<int> vInt1 = {1, 2};
    cout << "Origin vector:";
    print_vi(vInt1);
    test(vInt1);
    cout << "After test: ";
    print_vi(vInt1);
    return 0;
}