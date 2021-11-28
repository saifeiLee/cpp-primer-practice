#include <memory>
#include <iostream>
#include <string>
#include <vector>
#include <fstream>

using namespace std;

class Equal
{
public:
    Equal() = default;
    Equal(int b) : base(b) {}
    bool operator()(int i)
    {
        return i == base;
    }

private:
    int base;
};

int main()
{
    Equal eq(5);
    bool res = eq(1);
    cout << res << endl;
    vector<int> vi = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    replace_if(vi.begin(), vi.end(), Equal(5), 10);
    for (auto i : vi)
    {
        cout << i << " ";
    }
    cout << endl;
    return 0;
}