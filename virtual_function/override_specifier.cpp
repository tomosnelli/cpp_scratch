#include <iostream>

class Base {
	public:
		virtual void say_hi() const {
			std::cout << "output from Base class instance\n";
		}
		virtual ~Base(){}
};

class Derived: public Base {
	public:
		// if the function signature is not the exact same,
		// the compiler will see it as redefinition and use static binding

		// put override here to check that it is binded dynamically
		// so if the function signatures don't match you can get an error message
		// you can add const to this function signature
		virtual void say_hi() const override {
			std::cout << "output from Derived class instance\n";
		}
		virtual ~Derived(){}
};


int main(){
	Base *ptr1 = new Base();
	ptr1->say_hi();

	Derived *ptr2 = new Derived();
	ptr2->say_hi();

	Base *ptr3 = new Derived();
	ptr3->say_hi();					// this will bind to Base class say_hi method. But we want it to bind to Derived

	return 0;
}
