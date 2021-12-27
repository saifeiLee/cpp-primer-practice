#include <memory>
#include <iostream>
#include <string>
#include <vector>
#include <fstream>

using namespace std;

class DebugDelete
{
public:
    DebugDelete(ostream &s = cerr) : os(s) {}
    template <typename T>
    void operator()(T *p) const
    {
        os << "deleting unique_ptr" << endl;
        delete p;
    }

private:
    ostream &os;
};

template <typename T>
class Blob
{
    template <typename It>
    Blob(It b, It e);
};

template <typename A>
template <typename It>
Blob<A>::Blob(It b, It e)
{
}
int main()
{
    unique_ptr<int, DebugDelete> p(new int, DebugDelete());
    unique_ptr<string, DebugDelete> sp(new string, DebugDelete());
}