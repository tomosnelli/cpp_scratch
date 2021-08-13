# include <iostream>

// dynamic binding

// when there is a virtual function you need to provide a virtual destructor
// warnings when destroying a polymorphic class type Account with out virtual destructor is not defined

class Account {
	public:
		// add virtual down here
		// whenever you come at any derived object via a base class pointer,
		// or a base class reference, the appropriate function withdraw will
		// be dynamically bound
		virtual void withdraw(double amount) {
			std::cout << "Scope => Account::withdraw\n";
		}

		// you only need to provide a virtual destructor here at the base class
		// but it is better practice to add virtual destructor for each class
		virtual ~Account(){std::cout << "Account::destructor\n";}
};

class Checking: public Account {
	public:
		// don't need to add virutal for the derived classes,
		// but good practice to add it anyway
		virtual void withdraw(double amount) {
			std::cout << "Scope => Checking::withdraw\n";
		}

		~Checking(){std::cout << "Checking::destructor\n";}
};

class Savings: public Account {
	public:
		virtual void withdraw(double amount) {
			std::cout << "Scopt => Savings::withdraw\n";
		}

		~Savings(){std::cout << "Savings::destructor\n";}
};

class Trust: public Account {
		virtual void withdraw(double amount) {
			std::cout << "Scope => Trust::withdraw\n";
		}

		~Trust(){std::cout << "Trust::destructor\n";}
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

	// free up memory on heap
	delete ptr1;
	delete ptr2;
	delete ptr3;
	delete ptr4;
}
