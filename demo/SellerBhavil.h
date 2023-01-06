#ifndef BHSL
#define BHSL
#include"Seller.h"
#include<iostream>
#include<string>
#include<vector>
#include"Product.h"

using namespace std;

class SellerBhavil : public Seller{
    string productName, sellerName = "Bhavil";
    vector<string> prodStrList, strForListing;
    vector<Product> prodList;
    int prodID = 0, reqID = 0;
    string prodUniqName;

    SellerBhavil(string productName, Product prod){
        this->productName = productName;
        this->prodID++;
        this->reqID++;
        this->prodUniqName = this->sellerName + "-" + this->productName;
        this->prodList.push_back(prod);
        this->prodStrList.push_back(prod.stringifiedProduct);
        this->strForListing.push_back(to_string(this->reqID) + " " + this->productName + " " + this->prodUniqName + " " + to_string(prod.price) + " " + to_string(prod.quantity));
    }
};

#endif