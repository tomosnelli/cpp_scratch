#include <iostream>
#include <iomanip>

int main(){
	double a {123456789.123456789};
	double b {1234.5678};
	double c {1234.0};

	std::cout << "--Default---------------" << std::endl;
	std::cout << a << "\n";
	std::cout << b << "\n";
	std::cout << c << "\n";

	std::cout << "--Set Precision 2----------" << std::endl;
	std::cout << std::setprecision(2);
	std::cout << a << "\n";
	std::cout << b << "\n";
	std::cout << c << "\n";

	std::cout << "--Set Precision 5----------" << std::endl;
	std::cout << std::setprecision(5);
	std::cout << a << "\n";
	std::cout << b << "\n";
	std::cout << c << "\n";

	std::cout << "--Set Precision 9----------" << std::endl;
	std::cout << std::setprecision(9);
	std::cout << a << "\n";
	std::cout << b << "\n";
	std::cout << c << "\n";

	std::cout << "--Set Precision 3 and Fixed----------" << std::endl;
	std::cout << std::setprecision(3) << std::fixed;
	std::cout << a << "\n";
	std::cout << b << "\n";
	std::cout << c << "\n";

	std::cout << "--Set Precision 3 and Fixed and Scientific notation----------" << std::endl;
	std::cout << std::setprecision(3) << std::scientific;
	std::cout << a << "\n";
	std::cout << b << "\n";
	std::cout << c << "\n";

	// set things back to default
	std::cout.unsetf(std::ios::scientific | std::ios::fixed);
	std::cout << std::resetiosflags(std::ios::showpos);

	std::cout << "--precision 10 - showpoint----------" << std::endl;
	std::cout << std::setprecision(10) << std::showpoint;
	std::cout << a << "\n";
	std::cout << b << "\n";
	std::cout << c << "\n";

	// set back to default
	std::cout.unsetf(std::ios::scientific | std::ios::fixed);
	std::cout << std::setprecision(6);
	std::cout << std::resetiosflags(std::ios::showpoint);

	return 0;
}
