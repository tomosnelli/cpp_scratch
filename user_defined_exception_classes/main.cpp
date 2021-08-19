#include <iostream>

class DivideByZeroException {

};

class NonNaturalValueException {

};

double waru(int denominator, int molecular){
	if(denominator == 0){
		throw DivideByZeroException();
	}
	if(denominator < 0 || molecular < 0){
		throw NonNaturalValueException();
	}
	return static_cast<double>(molecular) / denominator;
}

int main(){
	int d {};
	int m {};
	double result {};

	std::cout << "Enter Denominator: ";
	std::cin >> d;
	std::cout << "Enter Molecular: ";
	std::cin >> m;

	try {
		result = waru(d, m);
	}
	catch (const DivideByZeroException &exp){
		std::cerr << "DIVIDE BY ZERO ERROR" << std::endl;
	}
	catch (const NonNaturalValueException &exp){
		std::cerr << "Passed parameters are not natural numbers" << std::endl;
	}
	std::cout << result << std::endl;
	std::cout << "Program End" << std::endl;

	return 0;
}
