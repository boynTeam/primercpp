#include "person.hpp"

std::istream &read(std::istream &is, Person &p1)
{
    string name;
    string address;
    is >> name >> address;
    p1.setAddress(address);
    p1.setName(name);
}

std::ostream &print(std::ostream &os, const Person &p1)
{
    os << p1.getName() << p1.getAddress();
}

Person::Person(std::istream& is) {
    read(is,*this);
}