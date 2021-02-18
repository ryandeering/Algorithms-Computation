#include "Customer.h"
#include "Employee.h"
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

bool compare(Person* ptr, Person* ptr2)
{
	if (*ptr < *ptr2) {
		return true;
	}
	else
		return false;
} //uses the overloaded operator while being able to use the standard library sort.

int main()
{
	
	//Ryan Deering - X00144631
	//Algorithms and Computation - Lab 1B
	
	
	
	
	/*Person* personPtr = new Person("Mark");
	personPtr->printname();
	cout << endl;
	personPtr = new Employee("Tom", 34000.0);
	personPtr->printname();
	personPtr = new Customer("Ed", "and I want to make a complaint");
	personPtr->printname();
	cout << endl;*/

	vector<Person*> pArray(3);

	pArray[0] = new Customer("Zebra", "and I want to cry");
	pArray[1] = new Customer("Banana", "and I want to make a complaint");
	pArray[2] = new Employee("Monkey", 2000.0);


	//Bubble sort
	sort(pArray.begin(), pArray.end(), compare);


	for (int i = 0; i < pArray.size(); i++)
	{
		pArray[i]->printname();
	}

	//6. Rewrite the Person class so that it is an abstract class, and see what difference
	//this makes to your program.
	//It doesn't allow you to instantiate a base class as an object.




}

//