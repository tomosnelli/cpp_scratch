#include <iostream>
#include <iomanip>

int main(){
	int num {114514};


	// default
	std::cout << "\nDefault integer io manipulator displays" << std::endl;
	std::cout << std::dec << num << std::endl;
	std::cout << std::hex << num << std::endl;
	std::cout << std::oct << num << std::endl;

	// show base format
	std::cout << "\nShow Base format" << std::endl;
	std::cout << std::showbase;
	std::cout << std::dec << num << std::endl;
	std::cout << std::hex << num << std::endl;

	// 0 is the prefix for octal in c++
	std::cout << std::oct << num << std::endl;

	std::cout << "\nSet back with noshowbase" << std::endl;
	std::cout << std::noshowbase;
	std::cout << std::hex << num << std::endl;

	// display in uppercase
	std::cout << "\nShow in UPPERCASE" << std::endl;
	std::cout << std::showbase << std::uppercase;
	std::cout << std::hex << num << std::endl;

	// show unary operator +/-
	std::cout << std::showpos;

	int minus {-10};
	std::cout << "\nShow unary +/- operators" << std::endl;
	std::cout << minus << std::endl;
	std::cout << minus << std::endl;
	std::cout << num   << std::endl; 
	std::cout << std::noshowpos;

	return 0;
}
