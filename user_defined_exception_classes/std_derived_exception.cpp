#include <iostream>
#include <memory>

// note for std::exception derived exceptions

// syntax

// noexcept keyword not clear on definition
// most likely means do not throw exception from these methods
// do not implement exceptions in destructors

class IllegalAgeRange: public std::exception{
	public:
		IllegalAgeRange() noexcept = default;
		~IllegalAgeRange() = default;
		virtual const char* what() const noexcept {
			return "Illegal Age Range Exception";
		}
};


int main(){

	int age {};

	std::cout << "Enter Age: ";
	std::cin >> age;

	try {
		if(age < 0 || age > 120){
			throw IllegalAgeRange{};
		}
		std::unique_ptr<int> age = std::make_unique<int>(25);
	}
	catch (const IllegalAgeRange &exp){
		std::cerr << exp.what() << std::endl;
	}

	return 0;
}
