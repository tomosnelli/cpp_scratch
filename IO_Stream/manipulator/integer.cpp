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
	std::cout << std::oct << num << std::endl;

	return 0;
}
