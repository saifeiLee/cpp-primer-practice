#include <memory>
#include <iostream>
#include <string>
#include <vector>
#include <fstream>

using namespace std;

class Foo
{
public:
    Foo()
    {
        cout << "Foo()" << endl;
    }
    Foo sorted() &&;
    Foo sorted() const &;
    ~Foo()
    {
        cout << "~Foo()" << endl;
    }

private:
    vector<int> data;
};

Foo Foo::sorted() &&
{
    sort(data.begin(), data.end());
    return *this;
}

int main()
{
}