#include <iostream>
#include <vector>
#include <algorithm>

class Person {
	friend std::ostream &operator<<(std::ostream &os, const Person &p);

	private:
		std::string name;
		int age;
	public:
		Person()=default;
		Person(std::string iname, int iage)
			:name{iname}, age{iage} {}
		bool operator<(const Person &rhs) const {
			return this->age < rhs.age;
		}
		bool operator==(const Person &rhs) const {
			return (this->name == rhs.name && this->age && rhs.age);
		}
};

std::ostream &operator<<(std::ostream &os, const Person &p) {
	os << p.name << ":" << p.age;
	return os;
}

void display2(const std::vector <int> &vec){
	std::cout << "[ ";
	std::for_each(vec.begin(), vec.end(),
					[](int x){ std::cout << x << " "; });
	std::cout << "]" << std::endl;
}

template <typename T>
void display(const std::vector<T> &vec){
	std::cout << "[ ";
	for(const auto &item: vec){
		std::cout << item << " ";
	}
	std::cout << "]" << std::endl;
}

void test1(){
	std::cout << "Test1==========================" << std::endl;

	std::vector<int> vec {1,2,3,4,5};
	display(vec);
}

int main(){
	test1();
	return 0;
}
