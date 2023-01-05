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

void DemoPortal::showOutput(){
    // 1. take the list in a vector
    // 2. sort the list as per the given order using comparator sort
    // 3. then show the sorted vector as output
}

void DemoPortal::takeInputs(){
    // Here, we will take inputs as given in the problem statement and store it into inputsFromPlatformList vector
	string inputFirst = "";
	string portalID = "", requestID = "", action = "", category = "", productID = "";
	int quantity;
	// add and End statement 
	while(inputFirst != "End"){
		cin>>portalID>>requestID>>action;
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