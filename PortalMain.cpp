#include"DemoPortal.h"
#include<iostream>
#include<string>

using namespace std;

int main(){
	DemoPortal portalObj;
	string command;
	getline(cin, command);
	portalObj.processUserCommand(command);
	portalObj.checkResponse();
	return 0;
}