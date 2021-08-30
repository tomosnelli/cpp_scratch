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
	std::vector<int> num {1, 2, 3, 4, 5};
	std::vector<int>::const_iterator iter = num.begin();
	// auto iter = num.cbegin() is equilvalent to the line above

	while(iter != num.end()){
		std::cout << *iter << std::endl;
		iter++;
	}

	iter = num.begin();
	while(iter != num.end()){
		// *iter = 0		this gives a compiler error
		iter++;
	}
}

void test4(){

	// iterator over vector
	std::vector<int> vect {1,2,3,4,5};
	auto iter = vect.rbegin();			// reverse iterator over vector of ints, start at 5
	std::cout << *iter << std::endl;
	while(iter != vect.rend()){
		std::cout << *iter << std::endl;
		iter++;
	}

	// iterator over list
	std::list<std::string> name {"Tomo", "Kaneko", "Snelling"};
	auto iter1 = name.crbegin(); // iterator over list of strings point to Snelling
	std::cout << *iter1 << std::endl;
	iter1++;
	std::cout << *iter1 << std::endl;

	// iterator over map, a python dictonary equivalent
	std::map<std::string, std::string> favorites {
		{"raindrops", "roses"},
		{"whiskers", "kittens"},
		{"Bright copper", "Kettles"}
	};
	auto iter2 = favorites.begin();
	while(iter2 != favorites.end()){
		std::cout << iter2->first << " : " << iter2->second << std::endl;
		iter2++;
	}
}

void test5(){
	
}

int main(){
	// test1();
	// test2();
	// test3();
	test4();
	// test5();
	return 0;
}
