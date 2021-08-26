#include <iostream>
#include <string>

template <int N>		// make it a template with out a typename but an actual value
class Array{
	int size {N};
	int values[N];

	friend std::ostream &operator<<(std::ostream &os, const Array &ar){
		os << "[";
		for(const auto &val: ar.values){
			os << val << " ";
		}
		os << "]" << std::endl;
		return os;
	}

	public:
		Array() = default;
		Array(int init_val){
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
		int &operator[](int index) {
			return values[index];
		}
};

int main(){
	Array<5> list;
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

	Array<100> alist {1};
	std::cout << "The size of alist => " << alist.get_size() << std::endl;
	std::cout << alist << std::endl;

	return 0;
}
