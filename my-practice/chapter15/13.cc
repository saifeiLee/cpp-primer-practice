#include <memory>
#include <iostream>
#include <string>
#include <vector>
#include <fstream>

using namespace std;

class base
{
public:
    base(string n = "test123") : basename(n) {}
    string name() { return basename; }
    virtual void print(ostream &os) { os << basename << endl; }

private:
    string basename;
};

class derived : public base
{
public:
    derived(string n = "derived") : name(n) {}
    void print(ostream &os) override
    {
        base::print(os);
        os << "calling derived print" << endl;
    }

    string getName()
    {
        return name;
    }

private:
    string name;
};

int main()
{
    base bobj;
    base *bp1 = &bobj;
    base &br1 = bobj;
    derived dobj;
    base *bp2 = &dobj;
    base &br2 = dobj;

    //
    cout << "1" << endl;
    bobj.print(cout);
    cout << "2" << endl;
    dobj.print(cout);
    cout << "3" << endl;
    bp1->print(cout);

    cout << "4" << endl;
    bp2->name();
    cout << "5" << endl;
    br1.print(cout);
    cout << "6" << endl;
    br2.print(cout);

    return 0;
}