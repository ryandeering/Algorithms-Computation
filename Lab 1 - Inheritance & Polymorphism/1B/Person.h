#pragma once 
#include <string>
#include <iostream>
using namespace std;
class Person {
public:
	Person(string);
	virtual void printname() const = 0;
	virtual ~Person();
	bool operator<(const Person& rhs) const;
protected:
	string name;
};

//Making the Person class abstract will make it so an object from the base class can't be created.