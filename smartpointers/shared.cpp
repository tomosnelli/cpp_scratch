#include <iostream>
#include <memory>

int main(){
	std::shared_ptr<int> ptr1 = std::make_shared<int>(100);
	std::cout << "USE COUNT=> " << ptr1.use_count() << std::endl;

	std::shared_ptr<int> ptr2 {ptr1};
	std::cout << "USE COUNT=> " << ptr2.use_count() << std::endl;

	std::shared_ptr<int> ptr3;
	ptr3 = ptr1;
	std::cout << "USE COUNT=> " << ptr3.use_count() << std::endl;

	return 0;
}
