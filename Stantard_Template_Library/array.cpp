#include <iostream>
#include <array>
#include <algorithm>
#include <numeric>

void display(const std::array<int, 5> &are){
	std::cout << "[";
	for(const auto &i: are){
		std::cout << i << " ";
	}
	std::cout << "]" << std::endl;
}

void test1(){
	std::cout << "Test1===========================" << std::endl;
	std::array<int, 5> arr1 {1,2,3,4,5}; // double {{}} for c++11
	std::array<int, 5> arr2;

	display(arr1);
	display(arr2);

	arr2 = {10, 20, 30, 40, 50};

	display(arr1);
	display(arr2);

	std::cout << "Size of arr1 is => " << arr1.size() << std::endl;
	std::cout << "Size of arr2 is => " << arr2.size() << std::endl;

	arr1[0] = 1000;
	arr1.at(1) = 810;
	display(arr1);

	std::cout << "Front of arr2 => " << arr2.front() << std::endl;
	std::cout << "Back of arr2 => " << arr2.back() << std::endl;
	std::cout << std::endl;
}

void test2(){
	std::cout << "Test2========================" << std::endl;
	std::array<int, 5> arr1 {1,2,3,4,5};
	std::array<int, 5> arr2 {10,20,30,40,50};

	display(arr1);
	display(arr2);

	arr1.fill(0);
	display(arr1);
	display(arr2);

	std::cout << std::endl;

}

void test3(){
	std::cout << "Test3========================" << std::endl;

	std::array<int, 5> arr1 {1,2,3,4,5};

	int *ptr = arr1.data();
	std::cout << ptr << " <= pointer" << std::endl;
	*ptr = 1000;
	display(arr1);
	std::cout << std::endl;
}

void test4(){
	std::cout << "Test4========================" << std::endl;

	std::array<int, 5> arr1 {4,1,2,3,5};
	display(arr1);

	std::sort(arr1.begin(), arr1.end());
	display(arr1);

	std::cout << std::endl;
}

void test5(){
	std::cout << "Test5========================" << std::endl;

	std::cout << std::endl;
}

void test6(){
	std::cout << "Test5========================" << std::endl;

}

void test7(){
	std::cout << "Test5========================" << std::endl;

}

void test8(){
	std::cout << "Test5========================" << std::endl;

}

int main(){
	//test1();
	//test2();
	//test3();
	test4();

	return 0;
}
