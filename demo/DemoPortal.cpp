#include<algorithm>
#include<bits/stdc++.h>
#include"Product.h"
#include<iostream>
#include<fstream>
#include<vector>
#include<string>
#include"DemoPortal.h"

using namespace std;

void DemoPortal::writeToFile(){
    this->takeInputs();
    // taking the inputs and writing them all to the PortalToPlatform.txt file
    // the inputs are stored in inputsFromPlatformList
	ofstream out;
	out.open("PortalToPlatform.txt");
	for(auto it : inputsFromPlatformList){
        out<<it;
    }
	out.close();
    
}

void DemoPortal::getResponseFromPlatform(){
    string tempInputString = "";
	ifstream in;
    // taking the input in tempInputString and then pushing it back to outputsSentToFile vector
    // this way, we will store the response from platform inside a vector
    // I have to put this inside a while loop
    in.open("PlatformToPortal.txt");
	while(in.eof() == 0){
		in>>tempInputString;
		this->outputsSentToFile.push_back(tempInputString);
	}
	in.close();
}

void DemoPortal::showOutput(string command){
	stringstream ss(command);
    string word;
	vector<string> inputList;
    while(ss>>word){
		inputList.push_back(word);
	}

    // 1. take the list in a vector
	if(inputList[0] == "List"){
		ifstream in;
		vector<string> dataInPlat2Portal;
		string tempStr;
		in.open("PlatformToPortal.txt");
		while(in.eof() == 0){
			in>>tempStr;
			stringstream ss(tempStr);
			string word;
			while(ss>>word){
    // 2. sort the list as per the given order using comparator sort
				if(inputList[1] == "Book"){
					if(inputList[2] == "Name"){
						sort(bookList.begin(), bookList.end(), Name);				
					}
					else{
						sort(bookList.begin(), bookList.end(), Price);
					}
				}
				else{
					if(inputList[2] == "Name"){
						sort(mobileList.begin(), mobileList.end(), Name);				
					}
					else{
						sort(mobileList.begin(), mobileList.end(), Price);
					}
				}
			}
			stringifyLists();
			if(inputList[1] == "Book"){
				for(auto it : this->bookStrList){
					//print it's string
					cout<<it;
				}
			}
			else{
				for(auto it : this->mobileStrList){
					//print it's string
					cout<<it;
				}
			}
	// 3. then show the sorted vector as output
		}
		in.close();
	}
	else if(inputList[0] == "Buy"){
		string productID = inputList[1];
		int quantity = 0;
		stringstream convToInteger(inputList[2]);
		convToInteger>>quantity;
		// Check if we have enough of the product in the protal, if tyes, give Success output, else failure
		
	}
	else if(inputList[0] == "Check"){
		this->outputsSentToFile.clear();
		this->getResponseFromPlatform();
	}	
}

void DemoPortal::takeInputs(){
    // Here, we will take inputs as given in the problem statement and store it into inputsFromPlatformList vector
	string inputFirst = "";
	string portalID = "", requestID = "", action = "", category = "", productID = "";
	int quantity;
	// add an End statement 
	while(inputFirst != "End"){
		cin>>portalID>>requestID>>action;
		if(portalID == "End"){
			break;
		}
		if(action == "Start"){
			Input inputObj = Input(portalID, requestID, action);
			this->inputsFromPlatformList.push_back(inputObj.stringifiedInput);
			// return the list of categories available, using category names from Globals.java
		}
		else if(action == "List"){
			cin>>category;
			Input inputObj = Input(portalID, requestID, action, category);
			this->inputsFromPlatformList.push_back(inputObj.stringifiedInput);
			// where <Catgeory> is one of the category names in Globals.java
			// should get back the list of products of the specified category
		}
		else if(action == "Buy"){
			cin>>productID>>quantity;
			Input inputObj = Input(portalID, requestID, action, productID, quantity);
			this->inputsFromPlatformList.push_back(inputObj.stringifiedInput);
			// where ProductID was the value sent by the Seller earlier
		}		
	}
}

void DemoPortal::stringifyLists(){
	// here, I will be making a list of the products, and store them in 2 vectors, 1 for mobile and 1 for books.
	this->bookStrList.clear();
	this->mobileStrList.clear();
	for(auto it : this->bookList){
		this->bookStrList.push_back(it.stringifiedProduct);
	}
	for(auto it : this->mobileList){
		this->mobileStrList.push_back(it.stringifiedProduct);
	}
}

int Name(Product* p1, Product* p2){
    return p1->getName().compare(p2->getName());
}

int Price(Product* p1, Product* p2){
    if(p1->getPrice() == p2->getPrice()) {
		return 0;
	}
	else if(p1->getPrice() > p2->getPrice()){
        return 1;
    }
	else{
        return -1;
    }
}