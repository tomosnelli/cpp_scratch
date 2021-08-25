#include <iostream>
#include <string>
#include <vector>

// Template classes are typically completely contained in header files
// So, we would have the template class in Item.h and no Item.cpp file
// would be used

template <typename T>
class Item {
	private:
		std::string name;
		T value;
	public:
		Item(std::string name, T value) : name{name}, value{value}{

		}
		std::string get_name() const {return name;}
		T get_value() const {return value;}
};

template <typename T1, typename T2>
struct My_Pair {
	T1 first;
	T2 second;
};

int main(){
	Item<int> item1 {"Tom", 100};
	std::cout << item1.get_name() << " " << item1.get_value() << std::endl;

	Item<std::string> item2 {"Tom", "BCIT"};
	std::cout << item2.get_name() << " " << item2.get_value() << std::endl;

	return 0;
}
