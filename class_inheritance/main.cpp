#include <iostream>
#include "Account.h"
#include "Savings_Account.h"

using namespace std;

int main(){
	cout << "\n==============Account======================" << endl;

	Account tom{};

	tom.deposit(200000.0);
	tom.withdraw(100.00);

	cout << endl;

	Account *p_acc {nullptr};
	p_acc = new Account();
	p_acc->deposit(1000.0);
	p_acc->withdraw(500.0);
	delete p_acc;

// use saving account class

	cout << "\n==============Account======================" << endl;
	Savings_Account tom_sav {};
	tom_sav.deposit(2000.0);
	tom_sav.withdraw(500.0);	

	cout << endl;

	Savings_Account *p_sav_acc {nullptr};
	p_sav_acc = new Savings_Account();
	p_sav_acc->deposit(1000.0);
	delete p_sav_acc;
	return 0;
}
