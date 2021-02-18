#include "Book.h"

Book::Book() {
	netPrice = 0;
}

Book::Book(double price) {
	netPrice = price;
}

double Book::getGrossPrice() {
	return netPrice; //no VAT, hence reimplementation
}