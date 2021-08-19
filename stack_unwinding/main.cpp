#include <iostream>
void A();
void B();
void C();

void A(){									// #8 check for exception handling. pop off stack
	std::cout << "Start A\n";	// #1
	B();						// #2
	std::cout << "End A\n";
}

void B(){									// #7 check for exception handling. pop off stack
	std::cout << "Start B\n";	// #3
	C();						// #4
	std::cout << "End B\n";
}

void C(){
	std::cout << "Start C\n";	// #5
	throw 0;					// #6	 This is where stack unwinding starts.
	std::cout << "End C\n";	// this part of the program will not run

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
	catch(int &error){							// #9 A() exits and there is an error handling here
		std::cerr << "Caught Error in main" << std::endl;	// #10
	}
	std::cout << "Exiting program\n";			// #11

	return 0;
}
