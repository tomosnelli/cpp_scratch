#include <iostream>

// only natural numbers
double calculate(int denominator, int molecular){
	if (denominator == 0){
		throw 0;
	}
	if ( denominator < 0 || molecular < 0 ){
		throw std::string{"passed numbers are not natural"};
	}
	return static_cast<double>(molecular) / denominator;
}

int main(){
	int a {};
	int b {};
	double result {};

	std::cout << "Enter Denominator: ";
	std::cin >> a;
	std::cout << "Enter Molecular: ";
	std::cin >> b;

	try {
		result = calculate(a, b);
		std::cout << "Result => " << result << std::endl;
	}
	catch (int &error){
		std::cerr << "Zero Division Error" << std::endl;
	}
	catch (std::string &error){
		std::cerr << error << std::endl;
	}

	return 0;
}
