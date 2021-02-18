#pragma once
#include "Person.h"

class Customer : public Person {
private:
	string message;
public:
	Customer(string nameIn, string messageIn);
	void printname() const;
};

