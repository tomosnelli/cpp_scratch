#include <iostream>
#include <algorithm>

int main(){
	std::vector<int> vec {1,2,3};
	auto integer = std::find(vec.begin(), vec.end(), 3);

	if (integer != vec.end()){
		std::cout << *integer << std::endl;
	}
	return 0;
}
