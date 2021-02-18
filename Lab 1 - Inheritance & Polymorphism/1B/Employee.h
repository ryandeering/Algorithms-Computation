#pragma once
#include "Person.h"

class Employee : public Person {
private:
	double salary;

public:
	Employee(string, double);
	void printname() const;
};

