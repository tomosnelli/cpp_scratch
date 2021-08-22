#include <iostream>
#include <iomanip>

int main(){
	int num {114514};

	std::cout << std::dec << num << std::endl;
	std::cout << std::hex << num << std::endl;
	std::cout << std::oct << num << std::endl;

	return 0;
}
