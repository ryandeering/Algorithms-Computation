#pragma once
#include "Product.h"
#include "Book.h"
#include "Software.h"
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

bool compareProducts(Product* p1, Product* p2) {

	return(p1->getGrossPrice() < p2->getGrossPrice());
}


int main() {
	
	
	//Ryan Deering - X00144631
	//Algorithms and Computation - Lab 1A
	
	
	
	

	const int n = 4;
	vector<Product*> pArray(n);
	Book* b1;
	Software* s1;

	double price;
	std::cout << "Enter your price for the book:\n";

	std::cin >> price;

	b1 = new Book(price);


	std::cout << "The gross price of the book is... \n" << b1->getGrossPrice();

	std::cout << "\n=============\n";


	pArray[0] = b1;


	std::cout << "Enter your price for the software:\n ";


	std::cin >> price;

	s1 = new Software(price);

	std::cout << "The gross price of the software is... \n" << s1->getGrossPrice();

	std::cout << "\n";

	pArray[1] = s1;

	string type = "";


	for (int i = 2; i < n; i++) {
		cout << "Type: \n";
		cin >> type;
		cout << "Price: \n";
		cin >> price;

		if (type == "Book" || type == "book" || type == "b") {
			pArray[i] = new Book(price);
		}
		else if (type == "Software" || type == "software" || type == "s") {
			pArray[i] = new Software(price);
		}
		else {
			cout << "Don't think that's right, buddy.";
		}
	}

	cout << "Unsorted: \n";
	for (auto itr : pArray) {
		cout << itr->getGrossPrice() << endl;
	} //I'm not sure why the numbers get so messed up. I can only assume the pointers get confused due to poor polymorphism.

//https://stackoverflow.com/questions/12702561/iterate-through-a-c-vector-using-a-for-loop
	
	
	std::sort(pArray.begin(), pArray.end(), compareProducts);


	cout << "Sorted: \n";
	for (auto itr : pArray) {
		cout << itr->getGrossPrice() << endl;
	}

	return(0);
}


