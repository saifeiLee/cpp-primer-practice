#ifndef PERSON_HPP
#define PERSON_HPP

#include <string>

struct Person
{
    std::string name;
    std::string address;
    std::string get_name() const;
    std::string get_address() const;
};

std::string Person::get_name() const
{
    return this->name;
}

std::string Person::get_address() const
{
    return this->address;
}

#endif