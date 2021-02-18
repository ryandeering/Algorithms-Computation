#include "Employee.h"
#include <iostream>

Employee::Employee(string nameIn, double salaryIn) : Person(nameIn) {
	salary = salaryIn;
}

void Employee::printname() const {
	Person::printname();
	cout << " and my salary is " << salary << endl;
}