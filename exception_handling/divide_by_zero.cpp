#include <iostream>

int main(){
	int a {0};
	int b {5};

	double result {};

	try {
		if(a == 0){
			throw 0;
		}
		result = static_cast<double>(b) / a;
		std::cout << result << std::endl;
	}
	catch (int &error){
		std::cerr << "Zero division Error" << std::endl;
	}

	std::cout << "End program" << std::endl;

	return 0;
}
