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

void test2(){
	std::vector<int> num {1, 2, 3, 4, 5};

	std::vector<int>::iterator iter = num.begin();
	while(iter != num.end()){
		std::cout << *iter << std::endl;
		iter++;
	}

	// change all vector elements to 0
	iter = num.begin();
	while(iter != num.end()){
		*iter = 0;
		iter++;
	}

	display(num);
}

void test3(){

}

int main(){
	// test1();
	test2();
	return 0;
}
