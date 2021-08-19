// try adding exception catching to various places in the functions.

#include <iostream>

void A();
void B();
void C();

void A(){
	std::cout << "Start A\n";
	B();
	std::cout << "End A\n";
}

void B(){
	// exception handling here
	std::cout << "Start B\n";
	try {
		C();
	}
	catch(int &error){
		std::cout << "Error caught in C()\n";
	}
	std::cout << "End B\n";
}

void C(){
	// what if I do some exception handling here?
	// try catch pair is expected here so I could not do that. Nothing to try here
	std::cout << "Start C\n";
	throw 0;
/*
	catch(int &error){
		std::cout << "Exception caught\n";
	}
*/
	std::cout << "End C\n";	

	// now that there is an error thrown, the program will check if there
	// is exception handling in C. If not it will go back to B and see
	// if there is exception handling. Then will move on to A because B
	// does not have exception handling. A does not have exception handling
	// as well the A() will be canceled. Each time the program confirms
	// there is no exception handling it pops the function off the stack
	// so you will not see the ending output on the stream
}

int main(){
	try {
		A();	// start here annotation in functions
	}
	catch(int &error){
		std::cerr << "Caught Error in main" << std::endl;
	}
	std::cout << "Exiting program\n";

	return 0;
}
