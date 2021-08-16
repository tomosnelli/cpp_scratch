#include <iostream>

// include memory headerfile
#include <memory>

int main(){
	std::unique_ptr<int> ptr { new int {100}};
	std::cout << *ptr << std::endl;

	return 0;
}
