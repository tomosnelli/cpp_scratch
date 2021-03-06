#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
#include <cctype>

class Person {
	private:
		std::string name;
		int age;
	public:
		Person() = default;
		Person(std::string name, int age)
			:name{name}, age{age} {}
		bool operator<(const Person &rhs) const {
			return this->age < rhs.age;
		}
		bool operator==(const Person &rhs) const {
			return (this->name == rhs.name && this->age == rhs.age);
		}
	
};

void find_test(){
	std::cout << "===========Find Test========" << std::endl;
	std::vector<int> vec {1,2,3,4,5};
	auto loc = std::find(std::begin(vec), std::end(vec), 1);

	if(loc != std::end(vec)){
		std::cout << "Found teh number: " << *loc << std::endl;
	} else {
		std::cout << "Could not find number" << std::endl;
	}

	std::list<Person> people {
		{"Tomo", 25},
		{"Ikeda", 25},
		{"Akira", 24}
	};

	auto loc1 = std::find(people.begin(), people.end(), Person{"Akira", 24});
	if(loc1 != people.end()){
		std::cout << "Found Person Akira" << std::endl;
	} else {
		std::cout << "Person not Found" << std::endl;
	}
}

void count_test(){
	std::cout << "=======Count Test=======" << std::endl;
	std::vector<int> vec {1,2,3,4,5,1,1,1};
	int num = std::count(vec.begin(), vec.end(), 1);
	std::cout << num << " occurrences of 1 found" << std::endl;
}

void count_if_test(){
	std::cout << "======Count If Test======" << std::endl;
	// now we use lambda expressions
	std::vector<int> vec {1,2,3,4,5,1,2,100};

	// return only if it meets the third lambda expression?
	int num = std::count_if(vec.begin(), vec.end(), [](int x) {return x % 2 == 0;});
	std::cout << num << " odd numbers found" << std::endl;
}

void replace_test(){
	std::cout << "========Replace Test=====" << std::endl;
	std::vector<int> vec {1,2,3,4,5};
	for(auto i: vec){
		std::cout << i << " ";
	}
	std::cout << std::endl << std::endl;

	std::replace(vec.begin(), vec.end(), 1, 810);
	for(auto j: vec){
		std::cout << j << " ";
	}
	std::cout << std::endl;
}

void all_of_test(){

	std::cout << "========All Of Test========" << std::endl;
	std::vector<int> vec{1,2,3,4,5,6,7,8,9,10,11,12,13,14};
	if(std::all_of(vec.begin(), vec.end(), [](int x) {return x > 10;})){
		std::cout << "All elements greater than 10" << std::endl;
	}
	else {
		std::cout << "Not all elements are greater than 10" << std::endl;
	}

	if(std::all_of(vec.begin(), vec.end(), [](int x){ return x < 20; })){
		std::cout << "All elements are smaller than 20" << std::endl;
	}
	else {
		std::cout << "Not all elements are smaller than 20" << std::endl;
	}
	std::cout << std::endl;
}

void string_transform_test(){
	std::string str {"Go to horny jail"};
	std::cout << "==========String Transform Test======" << std::endl;
	std::cout << "Before => " << str << std::endl;

	// parameters are...
	// where to start, where to end, and where to put the result, and what function to use
	// when using the scope resolution operator with no preceding keywords it mean to use "global scope"
	// because this is a function that has limited scope this makes sense to me
	std::transform(str.begin(), str.end(), str.begin(), ::toupper);
	std::cout << "After => " << str << std::endl;
	std::cout << std::endl;
}

int main(){

	find_test();
	count_test();
	count_if_test();
	replace_test();
	all_of_test();
	string_transform_test();

	return 0;
}
