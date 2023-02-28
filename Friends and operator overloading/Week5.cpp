#include <iostream>
#include "Vehicle.h"

using namespace std;


int main(int argc, char **argv)
{
	Vehicle original;
	Vehicle copy(original); // copy constructor by reference
	cout << "Original is: " << original << "copy is: " << copy << endl;
	cout << "Post Increment original: " << original++ << endl;
	cout << "Pre Increment copy:" << ++copy << endl;
	cout << "Pre Decrement original:" << --original << endl;
	cout << "Post Decrement copy:" << copy-- << endl;
	// should be true :
	cout << "Compare equality 1: " << (original == copy) <<  endl;
	//should be false:
	cout << "Compare equality 2: " << (--original == ++copy)  << endl;
	//should be true:
	cout << "Compare inequality: " << (original != copy) << endl;
	//This should make original = copy, and then return a Vehicle for output:
	cout << "\nAssignment operator: " << (original = copy) << endl;
	return 0;

}