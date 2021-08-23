#include <iostream>
#include <iomanip>
#include <string>

int main(){
	unsigned a {810};
	std::string b {"yaju"};

	std::cout << std::setw(10) << a << b << std::endl;
	std::cout << std::setw(10) << a << std::setw(10) << b << std::endl;

	// filling fixed with - setfill
	std::cout << std::setfill('-');
	std::cout << std::setw(10) << a << b << std::endl;

	// do more examples
	std::cout << std::setfill('_');	// this setting will last until undone.
	std::cout << std::setw(10) << a
			  << std::setw(10) << b
			  << std::endl;

	// do left justified
	std::cout << std::setw(10) << std::left << a
				<< std::setw(10) << std::left << b
				<< std::endl;

	// more example
	// for c++11 seems like you have to set setfill before setw and std::left
	std::cout << std::setfill('#');
	std::cout << std::setw(10) << std::left << a
				<< std::setfill('_') << std::setw(10) << std::left << b
				<< std::endl;

	return 0;
}
