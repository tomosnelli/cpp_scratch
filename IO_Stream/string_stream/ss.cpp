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

	// use a string as an input stream
	iss >> name >> num >> total;
	std::cout << std::setw(10) << std::left << name
				<< std::setw(5) << num
				<< std::setw(10) << total << std::endl;

	// put the gained info into a string with ostringstream object
	std::ostringstream oss {};
	oss << name << " " << num << " " << total;
	std::cout << oss.str() << std::endl;

	// Data validation
	int value {};
	std::string entry {};
	bool done = false;

	do {
		std::cout << "Enter an integer: ";
		std::cin >> entry;
		std::istringstream validator {entry};
		if(validator >> value){
			done = true;
		} else {
			std::cout << "Enter a valid integer" << std::endl;
		}
		// discrds the input buffer
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	} while(!done);

	std::cout << "Entered int => " << value << std::endl;

	return 0;
}
