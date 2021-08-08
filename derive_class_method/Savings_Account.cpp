#include "Savings_Account.h"

Savings_Account::Savings_Account(double balance, double interest_rate)
	:Account(balance), interest_rate{interest_rate} {
	
}

Savings_Account::Savings_Account()
	:Savings_Account{0.0, 0.0} {
	
}

void Savings_Account::deposit(double amount){
	amount = amount + (amount * (interest_rate/100));
	Account::deposit(amount);
}

double Savings_Account::display_balance() const {
	return balance;
}

double Savings_Account::display_rate() const {
	return interest_rate;
}

std::ostream &operator<<(std::ostream &os, const Savings_Account &account) {
	os << "Savings Account balance: " << account.display_balance() << "\nInterest Rate: " << account.display_rate() << std::endl;
	return os;
}
