#include <iostream>

class Base
{
public:
    std::size_t size() const { return n; }

protected:
    std::size_t n;
};
class Derived : private Base
{
public:
    using Base::size;
};

int main()
{
    Derived d;
    d.size();

    Base *b;
    // b = &d;
}
