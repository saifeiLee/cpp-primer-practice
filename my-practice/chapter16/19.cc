#include <iostream>
#include <vector>
using namespace std;

template <typename T>
void print(const T &c)
{

    for (typename T::size_type i = 0; i < c.size(); i++)
    {
        cout << c.at(i) << " ";
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