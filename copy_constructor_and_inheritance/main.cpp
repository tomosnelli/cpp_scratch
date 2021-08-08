#include <iostream>

using namespace std;

class Base {
	private:
		int value;
	public:
		Base()
			:value {0} {
			cout << "Base class no-args constructor invoked" << endl;
		}
		Base(int x)
			:value {x} {
			cout << "Base overloaded constructor invoked" << endl;
		}
		Base(const Base &other)
			:value {other.value} {
			cout << "Base copy constructor invoked" << endl;
		}
		Base &operator=(const Base &right) {
			cout << "Base overloaded = operator" << endl;
			if (this == &right){
				return *this;
			}
			value = right.value;
			return *this;
		}
		~Base(){ cout << "Base Destructor" << endl; }
};

class Derived: public Base {
	private:
		int doubled_value;
	public:
		Derived():
			Base {} {
			cout << "Derived no-args constructor" << endl;
		}
		Derived(int x)
			:Base{x}, doubled_value {x * 2} {
			cout << "int Derived constructor" << endl;
		}
		Derived(const Derived &other)
			:Base(other), doubled_value {other.doubled_value} {
			cout << "Derived copy constructor" << endl;
		}
		Derived &operator=(const Derived &right) {
			cout << "Derived overloaded = operator" << endl;
			if (this == &right){
				return *this;
			}
			Base::operator=(right);
			doubled_value = right.doubled_value;
			return *this;
		}
		~Derived(){ cout << "Derived destructor\n"; }
};

int main(){
	Derived test {100};			// Overloaded constructor
	Derived test1 {test};		// Copy constructor
	test = test1;				// Copy assignment
	return 0;
}
