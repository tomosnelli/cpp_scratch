// Constructors and Destructors with inheritance

#include <iostream>

using namespace std;

class Base {
	private:
		int value;
	public:
		Base(): value{0} {cout << "Base class no-args constructor invoked" << endl;}
		Base(int x): value{x} {cout << "Base class (int) overloaded constructor invoked" << endl;}
		~Base(){cout << "Base Destrucor invoked" << endl;}
};


class Derived:public Base {
	private:
		int doubled_value;
	public:
		
};


int main(){
	// Base b;
	Base b{100};
	
	return 0;
}
