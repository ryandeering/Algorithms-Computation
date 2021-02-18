#include "Product.h"
using namespace std;


Product::Product() {
	netPrice = 0;
}

Product::Product(double price){
	netPrice = price;
}

double Product::getGrossPrice() {
	netPrice = netPrice * 1.21;
	return netPrice;
}

