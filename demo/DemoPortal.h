#ifndef DMPTL
#define DMPTL

#include<iostream>
#include<fstream>
#include<vector>
#include<string>
#include"Product.h"

using namespace std;

class Input{
public:
	string portalID = "", requestID = "", action = "", category = "", productID = "";
	int quantity = 0;
	int reqID = 0, prodID = 0;
	string stringifiedInput = "";
	Input(string portalID, string requestID, string action, string productID, int quantity){
		this->portalID = portalID;
		this->requestID = requestID;
		this->action = action;
		this->prodID++;
		this->reqID++;
		this->productID = productID;
		this->quantity = quantity;
		this->stringifiedInput = portalID + " " + to_string(this->reqID) + " " + action + " " + productID + " " + to_string(quantity);
		// for Buy
	}
	Input(string portalID, string requestID, string action){
		this->portalID = portalID;
		this->requestID = requestID;
		this->action = action;
		this->reqID++;
		this->prodID++;
		this->stringifiedInput = portalID + " " + to_string(this->reqID) + " " + action;
		// for Start 
	}
	Input(string portalID, string requestID, string action, string category){
		this->portalID = portalID;
		this->requestID = requestID;
		this->prodID++;
		this->action = action;
		this->category = category;
		this->reqID++;
		this->stringifiedInput = portalID + " " + to_string(this->reqID) + " " + action + " " + category;
		// for List 
	}
};

class DemoPortal{
    vector<string> inputsFromPlatformList;
    vector<string> outputsSentToFile;
	vector<Product> bookList, mobileList;
	vector<string> bookStrList, mobileStrList;
    // It has the following features:
    // 1. Take file input from platform's file
    // 2. Give file input to portal's file
    // 3. It will show the sorted lists as well
    
    void writeToFile();
    void getResponseFromPlatform();
    void showOutput(string command);
    void takeInputs();
	void disp(){
		for(auto it : this->outputsSentToFile){
			cout<<it;
		}
	}
	void stringifyLists();
public:
	void processUserCommand(string command){
		showOutput(command);
		writeToFile();
	}
	void checkResponse(){
		// checks for pending responses (in PortalToPlatform)
		// Displays response
		getResponseFromPlatform();
		disp();
	}
};

#endif