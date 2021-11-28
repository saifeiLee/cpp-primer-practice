#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class Person
{
public:
    int age;

    Person(int initialAge)
    {
        if (initialAge < 0)
        {
            cout << "Age is not valid, setting age to 0." << endl;
            age = 0;
        }
        else
        {
            age = initialAge;
        }
    }

    void yearsPasses()
    {
        this->age = ++(this->age);
    }

    void amIOld()
    {
        if (age < 13)
        {
            cout << "You are young." << endl;
        }
        else if (age >= 13 && age < 18)
        {
            cout << "You are a teenager." << endl;
        }
        else
        {
            cout << "You are old." << endl;
        }
    }
};

int main()
{
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int numberCase;
    cin >> numberCase;
    while (numberCase--) 
    {
        /* code */
        int age = 0;
        cin >> age;
        Person p(age);
        p.amIOld();
        p.yearsPasses();
        p.yearsPasses();
        p.yearsPasses();
        p.amIOld();
        if (numberCase > 1) {
            cout << endl;
        }
    }
    
    return 0;
}
