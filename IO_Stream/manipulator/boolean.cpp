#include <iostream>
#include <iomanip>

int main(){
	// default output
	std::cout << (10 == 10) << std::endl;
	std::cout << (1 > 2) << std::endl;

	// Set output to true/false format
	std::cout << std::boolalpha;
	std::cout << (10 == 10) << std::endl;
	std::cout << (1 > 2)	<< std::endl;
	return 0;
}
