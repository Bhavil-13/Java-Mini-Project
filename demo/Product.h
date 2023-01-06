#ifndef PROD
#define PROD
#include<string>
#include"Globals.h"

using namespace std;

class Product {
public:
    int quantity;
	float price;
	string productId;
	string name;
	Globals.Category category;
	// common queries to get category, unique name, price, and number available
	Globals.Category getCategory();
	string getName();
	string getProductID();
	float getPrice();
	int getQuantity();
	string stringifiedProduct;
	Product(string name, string productID, int quantity, float price){
		this->name = name;
		this->productId = productID;
		this->quantity = quantity;
		this->price = price;
		this->stringifiedProduct = this->productId + " " + this->name + " " + to_string(this->price) + " " + to_string(this->quantity);
	}

};

#endif