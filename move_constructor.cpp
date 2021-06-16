#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Ferret {
	private:
		string *name;
	public:
		// void set_name_value(string input){*name = input;}
		string *get_name(){return name;}
		// move constructor
		Ferret(string input); // constructor
		Ferret(Ferret &&source); // Move constructor
		~Ferret(); // destructor
};

// Ferret class constructor
Ferret::Ferret(string input){
	name = new string;
	*name = input;
	cout << "Constructor created " << *name << endl;
}

// Ferret class move constructor
Ferret::Ferret(Ferret &&source)
	:name{source.name} {
		cout << source.name << " moved to address => " << name << " " << *name << endl;
		cout << "Original address => " << source.get_name() << endl;
		source.name = nullptr;
}

// Ferret class destructor
Ferret::~Ferret(){
	if(name != nullptr){
		cout << "destructor freeing data for " << name << endl;
	} else {
		cout << "destructor freeing data for nullptr" << endl;
	}
	delete name;
}

// rather than making a new object and copying it around, move it around!

int main(){

	// try using the move constructor here
	vector<Ferret> ferrets;
	ferrets.push_back(Ferret{"Hail"});
	ferrets.push_back(Ferret{"Neko"});
	ferrets.push_back(Ferret{"Cat"});
	ferrets.push_back(Ferret{"tail"});

	return 0;
}
