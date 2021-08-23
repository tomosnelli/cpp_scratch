#include <iostream>
#include <iomanip>
#include <string>

int main(){
	unsigned a {810};
	std::string b {"yaju"};

	std::cout << std::setw(10) << a << b << std::endl;

	return 0;
}
