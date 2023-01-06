#include"Product.h"
#include<string>

using namespace std;

Globals::Category Product::getCategory(){
		return this->category;
}
		
string Product::getName() {
	return name;
}

string Product::getProductID() {
	return productId;
}

float Product::getPrice() {
	return price;
}


int Product::getQuantity() {
	return quantity;
}

