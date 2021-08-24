#include <iostream>
#include <iomanip>
#include <sstream>
#include <string>
#include <limits>

int main(){
	int num {};
	double total {};
	std::string name{};

	std::string info {"derp 100 123.4"};
	std::istringstream iss {info};

	iss >> name >> num >> total;
	std::cout << std::setw(10) << std::left << name
				<< std::setw(5) << num
				<< std::setw(10) << total << std::endl;

	return 0;
}
