#pragma once
#include "Customer.h"
#include <iostream>

Customer::Customer(string nameIn, string messageIn) : Person(nameIn) {
	message = messageIn;
}

void Customer::printname() const {
	Person::printname();
	cout << ",and " + message << endl;
}