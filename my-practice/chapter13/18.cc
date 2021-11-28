#include <memory>
#include <iostream>
#include <string>
#include <vector>
#include <fstream>

using namespace std;

class Employee
{
    static unsigned int seed;

private:
    /* data */
    string name;
    string::size_type id;

public:
    Employee() : id(seed++){};
    Employee(string n);
    ~Employee();
};

Employee::Employee(string n) : name(n), id(++seed)
{
}

Employee::Employee(const Employee &rhs) : name(rhs.name), id(++seed) {}
Employee &Employee::operator=(const Employee &rhs)
{
    name = rhs.name;
    id = ++seed;
    return *this;
}
Employee::~Employee()
{
}

int main()
{
}