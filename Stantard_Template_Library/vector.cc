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

	vec = {5,6,7,8,9};
	display2(vec);

	std::vector<int> vec1 (10, 100);	// ten 100s in the vector
	display(vec1);
}

void test2(){
	std::cout << "Test2========================" << std::endl;

	// capacity => a number that once exceeded by vec.size(), the stl will increase the size of vec
	std::vector<int> vec {1,2,3,4,5};
	display(vec);
	std::cout << "vec of type vector specs => ";
	std::cout << "size: " << vec.size() << ", ";
	std::cout << "max size: " << vec.max_size() << ", ";
	std::cout << "capacity: " << vec.capacity() << std::endl;

	// because we exceed the capacity size, the vec.size() will go to 10
	vec.push_back(6);
	display(vec);
	std::cout << "vec of type vector specs => ";
	std::cout << "size: " << vec.size() << ", ";
	std::cout << "max size: " << vec.max_size() << ", ";
	std::cout << "capacity: " << vec.capacity() << std::endl;

	// but what if we have limited memory? we can use the .shrink_to_fit() method
	vec.shrink_to_fit();
	display(vec);
	std::cout << "vec of type vector specs => ";
	std::cout << "size: " << vec.size() << ", ";
	std::cout << "max size: " << vec.max_size() << ", ";
	std::cout << "capacity: " << vec.capacity() << std::endl;

}

int main(){
	//test1();
	test2();

	return 0;
}
