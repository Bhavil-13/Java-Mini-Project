#ifndef GLBL
#define GLBL
#include<string>

using namespace std;

class Globals {

	// Currently only 2 categories of products
public:
    enum Category {
		Mobile,
		Book
	};
	
	// String names of the above to used for writing/reading to message files or user interface
	string getCategoryName(Category c) {
		switch(c) {
		case Mobile: 
			return "Mobile";
		case Book:
			return "Book";
		default:
			return "Error";
		}
	}

	string toPlatform = "PortalToPlatform.txt";
	string fromPlatform = "PlatformToPortal.txt";
		
};

#endif