#include <iostream>
#include <string>

using namespace std;

class Base
{
public:
    static void statemem();
};

class Derived: public Base {
    void f(const Derived&);
};


void Derived::f(const Derived & derived_obj) {
    Base::statemem();
    Derived::statemem();
    derived_obj.statemem();
    statemem();
}

int main()
{
}