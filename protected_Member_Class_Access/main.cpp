#include <iostream>

using namespace std;

class Base {
	public:
		int a {0};
		void display(){std::cout << a << ", " << b << ", " << c << endl;}
	protected:
		int b {0};
	private:
		int c {0};
};


class Derived: public Base {
	// a is public in parent
	// b is protected in parent so it is protected here to
	// c is not accessible
	public:
		void access_members(){
			a = 420;
			b = 19;	
			// c = 810; // not accesible. need to use a getter or setter in parent class
		}
	
};


int main() {
	cout << "===Base member access from base objects========" << endl;
	Base base;
	base.a = 100;	// can access with public inheritance
	// base.b = 200;	// compiler error
	// base.c = 100;	// compiler error

	cout << "===Base member access from derived objects=====" << endl;
	Derived d;
	d.a = 4000; // OK
	// d.b = 1;	// Error
	// d.c = 3;	// Error

	cout << base.a << endl;
	cout << d.a << endl;

	return 0;
}
