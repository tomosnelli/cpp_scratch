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

	// minor method. this will reserve 100 spaces in memory
	vec.reserve(100);

}

void test3(){
	std::cout << "Test3======================" << std::endl;

	std::vector<int> vec {1,2,3,4,5};
	display(vec);

	// no bounds checking for the subscript
	vec[0] = 100;

	// dot at method does bounds checking 
	vec.at(1) = 200;

	display(vec);
}

void test4(){
	std::cout << "Test4==========================" << std::endl;

	std::vector<Person> comedian {
		{"Joe Rogan", 54},
		{"Bill Burr", 54},
		{"Joey Diaz", 52}
	};

	display(comedian);

	Person p1 { "Tim Dillon", 40 };
	comedian.push_back(p1);

	comedian.push_back(Person{"Dough Stanhope", 55});
	display(comedian);

	// no need for constructors, just pass the parameters
	comedian.emplace_back("Ralphie May", 40);

	display(comedian);
}

void test5(){
	std::cout << "Test5=======================" << std::endl;

	std::vector<Person> comedian {
		{"Joe Rogan", 54},
		{"Bill Burr", 54},
		{"Joey Diaz", 52}
	};

	display(comedian);

	std::cout << "\nFront => " << comedian.front() << std::endl;
	std::cout << "Back => " << comedian.back() << std::endl;

	comedian.pop_back();
	display(comedian);
}

void test6(){
	std::cout << "Test6====================" << std::endl;

	std::vector<int> vec {1,2,3,4,5};
	display(vec);

	vec.clear();	// remove all elements
	display(vec);

	vec = {1,2,3,4,5,6,7,8,9,10};
	display(vec);
	vec.erase(vec.begin(), vec.begin()+2);
	display(vec);

	vec = {1,2,3,4,5,6,7,8,9,10};
	// remove all even numbers
	// this example is looping over a vector and removing items. not sure if that is good practice someone inform me on this
	auto iter = vec.begin();
	while(iter != vec.end()){
		if(*iter % 2 == 0){
			vec.erase(iter);
		}
		else {
			iter++;
		}
	}
	display(vec);
}

void test7(){
	std::cout << "Test7====================" << std::endl;

	std::vector<int> vec {1,2,3,4,5};
	std::vector<int> vec1 {10,20,30,40,50};

	display(vec);
	display(vec1);

	std::cout << std::endl;

	vec1.swap(vec);
	std::cout << "Display vec => ";
	display(vec);

	std::cout << "Display vec1 => ";
	display(vec1);
}

void test8(){
	std::cout << "Test8=========================" << std::endl;

	std::vector<int> vec {1,21,3,40,12};
	display(vec);
	std::sort(vec.begin(), vec.end());
	display(vec);
}

int main(){
	//test1();
	//test2();
	//test3();
	//test4();
	//test5();
	//test6();
	//test7();
	test8();

	return 0;
}
