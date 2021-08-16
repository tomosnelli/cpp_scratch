#include <iostream>
#include <memory>

using namespace std;

class B;	// forward declaration

class A {
	std::shared_ptr<B> b_ptr;
	public:
		void set_B(std::shared_ptr<B> &obj) {
			b_ptr = obj;
		}
		A(){ cout << "Constructor called" << endl; }
		~A(){ cout << "Destructor called" << endl; }
};

class B {
	// std::shared_ptr<A> a_ptr;	// make weak to break to strong circulare reference
	std::weak_ptr<A> a_ptr;
	public:
		void set_A(std::shared_ptr<A> &obj) {
			a_ptr = obj;
		}
		B(){ cout << "B Constructor called" << endl; }
		~B() { cout << "B Destructor called" << endl; }
};

int main(){

	// this kind of circulare referencing causes memory leak (look at line 19~20)
	// when destructing, only the pointers a&b will be destructed but the area on
	// heap will be left undeleted
	shared_ptr<A> a = make_shared<A>();
	shared_ptr<B> b = make_shared<B>();

	a->set_B(b);
	b->set_A(a);
	
	
	return 0;
}
