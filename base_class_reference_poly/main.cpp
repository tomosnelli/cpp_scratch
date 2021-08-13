# include <iostream>

class Account {
	public:
		virtual void withdraw(double amount) {
			std::cout << "Scope => Account::withdraw\n";
		}

		virtual ~Account(){std::cout << "Account::destructor\n";}
};

class Checking: public Account {
	public:
		virtual void withdraw(double amount) {
			std::cout << "Scope => Checking::withdraw\n";
		}

		virtual ~Checking(){std::cout << "Checking::destructor\n";}
};

class Savings: public Account {
	public:
		virtual void withdraw(double amount) {
			std::cout << "Scopt => Savings::withdraw\n";
		}

		virtual ~Savings(){std::cout << "Savings::destructor\n";}
};

class Trust: public Account {
		virtual void withdraw(double amount) {
			std::cout << "Scope => Trust::withdraw\n";
		}

		virtual ~Trust(){std::cout << "Trust::destructor\n";}
};


void do_withdraw(Account &account, double amount){
	account.withdraw(amount);
}

int main(){
	Account a;
	Account &ref = a;
	ref.withdraw(1000);		// Account::withdraw

	Trust tacc;

/*
	Trust t;
	Account &ref1 = t;
	ref1.withdraw(1000);	// Trust::withdraw
*/

/*
	Account a;
	Savings s;
	Checking c;
	Trust tr;
	
	// dynamically bound
	do_withdraw(a, 100);
	do_withdraw(s, 100);
	do_withdraw(c, 100);
	do_withdraw(tr, 100);
*/
	
	return 0;
}
