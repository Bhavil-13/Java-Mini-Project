#include"DemoPortal.h"

using namespace std;

int main(){
	DemoPortal portalObj;
	portalObj.writeToFile();
	portalObj.getResponseFromPlatform();
	portalObj.showOutput();

	return 0;
}