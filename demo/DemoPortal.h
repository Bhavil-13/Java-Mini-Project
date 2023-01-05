#ifndef DMPTL
#define DMPTL

#include<iostream>
#include<fstream>
#include<vector>
#include<string>

using namespace std;

class Input{
public:
	string portalID = "", requestID = "", action = "", category = "", productID = "";
	int quantity = 0;
	string stringifiedInput = "";
	Input(string portalID, string requestID, string action, string productID, int quantity){
		this->portalID = portalID;
		this->requestID = requestID;
		this->action = action;
		this->productID = productID;
		this->quantity = quantity;
		this->stringifiedInput = portalID + " " + requestID + " " + action + " " + productID + " " + to_string(quantity);
		// for Buy
	}
	Input(string portalID, string requestID, string action){
		this->portalID = portalID;
		this->requestID = requestID;
		this->action = action;
		this->stringifiedInput = portalID + " " + requestID + " " + action;
		// for Start 
	}
	Input(string portalID, string requestID, string action, string category){
		// for List 
		this->portalID = portalID;
		this->requestID = requestID;
		this->action = action;
		this->category = category;
		this->stringifiedInput = portalID + " " + requestID + " " + action + " " + category;
	}
};

class DemoPortal{
    vector<string> inputsFromPlatformList;
    vector<string> outputsSentToFile;
public:
    // It has the following features:
    // 1. Take file input from platform's file
    // 2. Give file input to portal's file
    // 3. It will show the sorted lists as well
    
    void writeToFile();
    void getResponseFromPlatform();
    void showOutput();
    void takeInputs();
};

#endif