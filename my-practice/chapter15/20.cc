#include <memory>
#include <iostream>
#include <string>
#include <vector>
#include <fstream>

using namespace std;

class Base
{
public:
    void pub_mem();

protected:
    char prot_mem;

private:
    char priv_mem;
};

// 1
struct Pub_Derv : public Base
{
    int f() { return prot_mem; }
    void memfcn(Base &b)
    {
        b = *this;
        cout << "Pub_Derv" << endl;
    }
};

//2
struct Priv_Derv : private Base
{
    int f1() { return prot_mem; }
    void memfcn(Base &b)
    {
        b = *this;
        cout << "Priv_Derv" << endl;
    }
};

// 3
struct Prot_Derv : protected Base
{
    int f2() { return prot_mem; }
    void memfcn(Base &b)
    {
        b = *this;
        cout << "Prot_Derv" << endl;
    }
};

// 4
struct Derived_from_public : public Pub_Derv
{
    int usebase() { return prot_mem; }
    void memfcn(Base &b)
    {
        b = *this;
        cout << "Derived_from_public" << endl;
    }
};

// 5
struct Derived_from_protected : protected Prot_Derv
{
    int usebase() { return prot_mem; }
    void memfcn(Base &b)
    {
        b = *this;
        cout << "Derived_from_protected" << endl;
    }
};

int main()
{
    Pub_Derv d1;
    Priv_Derv d2;
    Prot_Derv d3;
    Derived_from_public dd1;
    Derived_from_protected dd3;

    Base base;
    Base *p = new Base;
    p = &d1;
    // p = &d2;
    // p = &d3;

    d1.memfcn(base);    // Pub_Derv
    d2.memfcn(base);    // Priv_Derv
    d3.memfcn(base);    // Prot_Derv
    dd1.memfcn(base);   // Derived_from_public
    dd3.memfcn(base);   // Derived_from_protected
    return 0;
}