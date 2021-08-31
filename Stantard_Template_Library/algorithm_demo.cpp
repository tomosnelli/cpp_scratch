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

int main(){
	find_test();
	return 0;
}
