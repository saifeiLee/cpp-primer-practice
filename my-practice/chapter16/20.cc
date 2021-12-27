#include <iostream>
#include <vector>
using namespace std;

template <typename T>
void print(const T &c)
{

    for (auto iter = c.begin(); iter != c.end(); ++iter)
    {
        cout << *iter << " ";
    }
    cout << endl;
}

class Base
{
public:
    typedef size_t my_size_type;
};

int main()
{
    string s = "hello!";
    print(s);
    vector<int> vi = {1, 2, 3, 4, 5};
    print(vi);
    return 0;
}