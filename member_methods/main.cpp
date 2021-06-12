#include <iostream>
#include <string>
#include "Account.h"

int main(){
	Account tom_kaneko;
	tom_kaneko.set_balance(1000.0);
	double current_balance = tom_kaneko.get_balance();

	std::cout << current_balance << std::endl;
	return 0;
}
