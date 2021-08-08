#include <iostream>
#include "Savings_Account.h"

using namespace std;

int main(){
	Account tk {10000.0};
	cout << tk << endl;

	tk.deposit(500.0);
	cout << tk << endl;

	tk.withdraw(1000);
	cout << tk << endl;

	return 0;
}
