# include <iostream>

// binded with Account because of static binding

class Account {
	public:
		void withdraw(double amount) {
			std::cout << "Scope => Account::withdraw\n";
		}
};

class Checking: public Account {
	public:
		void withdraw(double amount) {
			std::cout << "Scope => Checking::withdraw\n";
		}
};

class Savings: public Account {
	public:
		void withdraw(double amount) {
			std::cout << "Scopt => Savings::withdraw\n";
		}
};

class Trust: public Account {
		void withdraw(double amount) {
			std::cout << "Scope => Trust::withdraw\n";
		}
};

int main(){
	std::cout << "\n ====pointers=====\n";
	Account *ptr1 = new Account();
	Account *ptr2 = new Savings();
	Account *ptr3 = new Checking();
	Account *ptr4 = new Trust();

	ptr1->withdraw(100);
	ptr2->withdraw(100);
	ptr3->withdraw(100);
	ptr4->withdraw(100);
}
