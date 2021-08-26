#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <list>

// display any vector of integers using range-based for loop
void display(const std::vector<int> &vec){
	std::cout << "[ ";
	for(auto const &i: vec){
		std::cout << i << " ";
	}
	std::cout << "]" << std::endl;
}


void test1(){
	std::cout << "\n---------------------------" << std::endl;
	std::vector<int> num{1, 2, 3, 4, 5};
	auto iter = num.begin();
	std::cout << *iter << std::endl;

	iter++;
	std::cout << *iter << std::endl;

	iter += 2;
	std::cout << *iter << std::endl;

	iter -= 2;
	std::cout << *iter << std::endl;

	iter = num.end() - 1;
	std::cout << *iter << std::endl;

}

int main(){
	test1();
	return 0;
}
