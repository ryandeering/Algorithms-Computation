#include "Person.h"
#include <iostream>

Person::Person(string nameIn) {
	name = nameIn;
}

void Person::printname() const {
	cout << "My name is " + name;
}

Person::~Person() {
	cout << "Base Destructor called\n";
}

bool Person::operator<(const Person& rhs) const
{
    if (name < rhs.name) {
        return true;
    }
    else
        return false;
}