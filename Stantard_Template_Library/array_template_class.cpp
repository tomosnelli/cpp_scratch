#include <iostream>
#include <string>

// use std::array instead of raw arrays whenever possible


template <typename T, int N>		// make it a template with out a typename but an actual value
class Array{
	int size {N};
	T values[N];

	friend std::ostream &operator<<(std::ostream &os, const Array<T, N> &ar){
		os << "[";
		for(const auto &val: ar.values){
			os << val << " ";
		}
		os << "]" << std::endl;
		return os;
	}

	public:
		Array() = default;
		Array(T init_val){
			for(auto &item: values){
				item = init_val;
			}
		};
		void fill(int val){
			for(auto &item: values){
				item = val;
			}
		}
		int get_size() const{
			return size;
		}

		// overload subscript operator for easy use
		T &operator[](int index) {
			return values[index];
		}
};

int main(){
	Array<int, 5> list;
	std::cout << "The size of list is => " << list.get_size() << std::endl;
	std::cout << list << std::endl;

	list.fill(0);
	std::cout << "The size of list is => " << list.get_size() << std::endl;
	std::cout << list << std::endl;

	list.fill(10);
	std::cout << list << std::endl;

	list[0] = 100;
	list[3] = 2;
	std::cout << list << std::endl;

	Array<int, 100> alist {1};
	std::cout << "The size of alist => " << alist.get_size() << std::endl;
	std::cout << alist << std::endl;

	return 0;
}
