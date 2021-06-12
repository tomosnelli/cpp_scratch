// specification of account
#ifndef _ACCOUNT_H_
#define _ACCOUNT_H_
#include <string>

class Account {
	private:
		double balance;
	public:
		std::string name;
		void set_balance(double value);
		double get_balance();
		void deposit(double value);
		double withdraw(double value);
};

#endif
