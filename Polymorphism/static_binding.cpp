#include <iostream>

class Base {
	public:
		void say() const {
			std::cout << "This is a base class\n";
		}
};

class Derived: public Base {
	public:
		void say() const {
			std::cout << "This is a derived class\n";
		}
};

void greetings(const Base &obj) {
	std::cout << "Greetings: ";
	obj.say();
}

int main(){
	Base b;
	b.say();

	Derived d;
	d.say();

	// when using function greetings, the parameter is declared as Base.
	// class instance d is a Derived class but also is a Base class.
	// so you can pass d as a parameter, but the class method that is called or statically binded
	// will be the class method from Base. This is where polymorphism is needed?
	greetings(b);
	greetings(d);


	// Derived object is a Base object
	// Soooo we can point to a Derived object but there will be problems
	Base *ptr = new Derived();
	ptr->say();
	// ↑this will use the Base class method to print a message to the output stream

	return 0;
}
