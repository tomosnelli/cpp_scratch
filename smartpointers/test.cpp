#include <iostream>
#include <memory>
#include <vector>

class Test {
	private:
		int data;
	public:
		Test(): data{0} {std::cout << "Test Constructor (" << data << ")" << std::endl;}
		Test(int data): data{data} {std::cout << "Test constructor (" << data << ")" << std::endl;}
		int get_data() const {return data;}
		~Test() {std::cout << "Test Destructor (" << data << ")" << std::endl;}
};

int main(){
	// raw pointer
	Test *ptr = new Test {1};
	delete ptr;

	// unique pointer
	std::unique_ptr<Test> Tptr { new Test{2} };

	// make_unique is available to c++14 my version is c++11 :(
	// I could use make_unique in c++11
	std::unique_ptr<Test> T1ptr = std::make_unique<Test>(114514);

	// smart pointer with move
	std::unique_ptr<Test> ptr3;

	ptr3 = std::move(T1ptr);

	std::cout << ptr3->get_data() << std::endl;

	return 0;
}
