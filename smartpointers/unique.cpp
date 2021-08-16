#include <iostream>

// include memory headerfile
#include <memory>

int main(){
	std::unique_ptr<int> ptr { new int {100}};
	// for C++14, there is make_unique available.
	// syntax goes like this
/*
	std::unique_ptr<int> ptr = make_unique<int>(100);
					or
	auto ptr = make_unique<int>(10000);
*/


	std::cout << *ptr << std::endl;

	// pointers will be auto deleted 

	return 0;
}
