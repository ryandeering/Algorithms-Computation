#pragma once
#include "Product.h"

class Book : public Product {
public:
	Book();
	Book(double price);
	double getGrossPrice();
};