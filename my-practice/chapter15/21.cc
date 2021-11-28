#include <iostream>

using namespace std;

class Base
{
public:
    virtual void print()
    {
        cout << "Base" << endl;
    }
};

class Derived : public Base
{

public:
    // Derived() { cout << "Derived()" << endl; }
    void print() override
    {
        cout << "Derived" << endl;
    }
    Derived(const Derived &d) : Base(d) {}

    Derived(Derived &&d) : Base(std::move(d)) {}
};

int main()
{
    Base b;
    Derived d;
    b.print();
    d.print();

    Base *pb = &b;
    Base *pd = &d;
    pb->print();
    pd->print();
    return 0;
}