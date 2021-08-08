#include "Account.h"

class Savings_Account: public Account {
	friend std::ostream &operator<<(std::ostream &os, Savings_Account &account);

	protected:
		double interest_rate;
	public:
		Savings_Account();
		Savings_Account(double balance, double interest_rate);
		void deposit(double amount);
		double display_balance() const;
		double display_rate() const;
};
