#include <string>
#include <iostream>
using std::string;
class Person
{
private:
    string name;
    string address;

public:
    Person() = default;
    Person(const string address,const string name): name(name),address(address) {};
    Person(std::istream&);
    string getName() const { return this->name; }
    string getAddress() const { return this->address; }
    void setName(string name) {this->name = name;}
    void setAddress(string address) {this->address = address;}
};

std::istream &read(std::istream &, Person &);
std::ostream &print(std::ostream &, const Person &);