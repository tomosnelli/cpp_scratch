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
	std::cout << std::setfill('_');
	std::cout << std::setw(10) << a
			  << std::setw(10) << b
			  << std::endl;

	return 0;
}
