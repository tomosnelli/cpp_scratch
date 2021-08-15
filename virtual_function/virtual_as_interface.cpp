#include <iostream>

// using pure virtual functions as an interface

class I_Printable {
	// prototype
	friend std::ostream &operator<<(std::ostream &os, const I_Printable &obj);
	public:
		// syntax for pure virtual function
		virtual void print(std::ostream &os) const = 0;
};

// Implement the print function
std::ostream &operator<<(std::ostream &os, const I_Printable &obj){
	obj.print(os);
	return os;
}

class Account: public I_Printable {
	public:
		virtual void withdraw(double amount){
			std::cout << "Account::withdraw\n";
		}
		virtual void print(std::ostream &os) const override {
			os << "Account::print\n";
		}
		virtual ~Account(){}
};

class Checking: public Account {
	public:
		virtual void withdraw(double amount){
			std::cout << "Checking::withdraw\n";
		}
		virtual void print(std::ostream &os) const override {
			os << "Checking::print\n";
		}
		virtual ~Checking(){}
};

class Savings: public Account {
	public:
		virtual void withdraw(double amount){
			std::cout << "Savings::withdraw\n";
		}
		virtual void print(std::ostream &os) const override {
			os << "Savings::print\n";
		}
		virtual ~Savings(){}
};

class Trust: public Account {
	public:
		virtual void withdraw(double amount){
			std::cout << "Trust::withdraw\n";
		}
		virtual void print(std::ostream &os) const override {
			os << "Trust::print\n";
		}
		virtual ~Trust(){}
};

int main(){

	Account *ptr = new Account();
	std::cout << *ptr << std::endl;

	Account *Cptr = new Checking();
	std::cout << *Cptr << std::endl;

	Account *Sptr = new Savings();
	std::cout << *Sptr << std::endl;

	delete ptr;
	delete Cptr;
	delete Sptr;

	return 0;
}
