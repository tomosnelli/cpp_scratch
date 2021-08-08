#include <iostream>
#include "Savings_Account.h"

using namespace std;

int main(){
// Account
	Account tk {10000.0};
	cout << tk << endl;

	tk.deposit(500.0);
	cout << tk << endl;

	tk.withdraw(1000);
	cout << tk << endl;

// Savings Account
	Savings_Account sa {1000, 5.0};
	cout << sa << endl;

	sa.deposit(1000);
	cout << sa << endl;

	sa.withdraw(1000);
	cout << sa << endl;

	return 0;
}
