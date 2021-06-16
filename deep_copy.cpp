#include <iostream>
#include <string>

using namespace std;

// and example of deep copy
// just delegate to the constructor when making a copy

class Ferret {
	public:
		void set_name(string input){*name = input;}
		string get_name(){return *name;}
		// constructor
		Ferret(string name);
		// copy constructor
		Ferret(const Ferret &source);
		// destructor
		~Ferret();
	private:
		string *name;
};

// constructor
Ferret::Ferret(string input){
	name = new string;
	*name = input;
}

//copy constructor
Ferret::Ferret(const Ferret &source)
	:Ferret{*source.name} {
	cout << "Deep copy constructor called" << endl;
}

// destructor
Ferret::~Ferret(){
	delete name;
}

void display_name(Ferret s){
	cout << s.get_name() << endl;
}

int main(){
	Ferret albino {"snow"};
	display_name(albino);
	cout << "Address for albino => " << &albino << endl;

	// copy the ferret name -deep copy
	Ferret sable {albino};
	display_name(sable);
	cout << "Address for sable => " << &sable << endl;

	return 0;
}
