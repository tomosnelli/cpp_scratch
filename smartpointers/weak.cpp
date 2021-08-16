#include <iostream>
#include <memory>

using namespace std;

class B;	// forward declaration

class A {
	std::shared_ptr<B> b_ptr;
	public:
		void set_B(std::shared_ptr<B> &obj) {
			b_ptr = b;
		}
		A(){ cout << "Constructor called" << endl; }
		~A(){ cout << "Destructor called" << endl; }
};

class B {
	std::shared_ptr<A> a_ptr;	// make weak to break to strong circulare reference
	public:
		void set_A(std::shared_ptr<A> &obj) {
			a_ptr = a;
		}
		B(){ cout << "B Constructor called" << endl; }
		~B() { cout << "B Destructor called" << endl; }
};

int main(){
	
	
	return 0;
}
