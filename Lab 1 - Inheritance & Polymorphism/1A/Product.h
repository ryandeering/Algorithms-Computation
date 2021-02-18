#pragma once
class Product {
protected:
	double netPrice;

public:
	Product();
	Product(double price);
	double getGrossPrice();
};