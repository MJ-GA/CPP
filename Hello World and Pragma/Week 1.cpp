// Week 1.cpp : Defines the entry point for the application.
//

#include "Week 1.h"



#define usingNameSpaces 0 ;

#if usingNameSpaces ==0
using namespace std;
int main()
{
#pragma message("Using namespaces");
	cout << "Hello World." << endl;
	return 0;
}
#else
int main()
{
#pragma message("Not using namespaces");
	std::cout << "Hello world!" << std::endl;
	return 0;
}
#endif
