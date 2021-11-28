#include <memory>
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <map>

using namespace std;
int add(int i, int j)
{
    return i + j;
}
auto mod = [](int i, int j)
{
    return i % j;
};

struct divide
{
    int operator()(int i, int j)
    {
        return i / j;
    }
};

class SmallInt
{
public:
    SmallInt(int i = 0) : val(i) {}
    explicit operator int() const { return val; }
    operator string() const { return to_string(val); }

private:
    size_t val;
};
int main()
{
    // map<string, int (*)(int, int)> binops;
    // binops.insert({"+", add});
    // binops.insert({"%", mod});
    // auto res1 = binops["+"](1, 2);
    // auto res2 = binops["%"](4, 2);
    // cout << res1 << " " << res2 << endl;

    SmallInt si = 4;
    auto res1 = static_cast<int>(si) + 4;
    auto res2 = static_cast<int>(si) + 3;
    // string s = "123";
    SmallInt sd = 3.14;
    // auto res3 = ss + s;
    auto res3 = sd + 3.14;
    cout << res1 << " " << res2 << " " << res3 << endl;
}