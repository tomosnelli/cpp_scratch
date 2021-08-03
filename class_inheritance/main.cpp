#include <iostream>
#include "Account.h"
#include "Savings_Account.h"

using namespace std;

int main(){
	cout << "\n==============Account Summary======================" << endl;

	Account tom{};

	tom.deposit(200000.0);
	tom.withdraw(100.00);

	cout << endl;

	Account *p_acc {nullptr};
	p_acc = new Account();
	p_acc->deposit(1000.0);
	p_acc->withdraw(500.0);
	delete p_acc;

	return 0;
}
