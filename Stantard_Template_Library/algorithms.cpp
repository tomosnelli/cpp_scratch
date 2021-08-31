#include <iostream>
#include <algorithm>

struct Square_Functor {
	void operator()(int x) {		// the function call operator is being overloaded
		std::cout << x * x << " ";
	}
};

//function pointer
void square(int x){
	std::cout << x * x << " ";
}

int main(){
	// std::find
	std::vector<int> vec {1,2,3,4,5};
	auto integer = std::find(vec.begin(), vec.end(), 3);

	if (integer != vec.end()){
		std::cout << *integer << std::endl;
	}

	// functor and for_each
	std::cout << "Functor" << std::endl;
	Square_Functor square;
	std::for_each(vec.begin(), vec.end(), square);
	std::cout << std::endl;

	// with function pointer
	std::cout << "Function pointer" << std::endl;
	std::for_each(vec.begin(), vec.end(), square);

	return 0;
}
