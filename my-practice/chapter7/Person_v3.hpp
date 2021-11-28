#ifndef PERSON_HPP
#define PERSON_HPP

#include <string>
using std::string;

struct Person;
std::istream &read(std::istream &input, Person &person);
std::ostream &print(std::ostream &output, const Person &person);

struct Person
{
    friend std::istream &read(std::istream &input, Person &person);
    friend std::ostream &print(std::ostream &output, const Person &person);

private:
    std::string name;
    std::string address;
    std::string get_name() const;
    std::string get_address() const;

public:
    Person() = default;
    Person(const string &name, const string &address) : name(name), address(address) {}
    Person(std::istream &input)
    {
        read(input, *this);
    }
};

std::string Person::get_name() const
{
    return this->name;
}

std::string Person::get_address() const
{
    return this->address;
}

std::istream &read(std::istream &input, Person &person)
{
    std::getline(input, person.name);
    std::getline(input, person.address);
    return input;
}

std::ostream &print(std::ostream &output, const Person &person)
{
    output << person.name << " " << person.address;
    return output;
}

#endif