#include <iostream>
#include <cstring>
#include "Ferret.h"


//No-args constructor
Ferret::Ferret()
	:name{nullptr} {
	name = new char[1];
	*name = '\0';
}

// Overloaded constructor
Ferret::Ferret(const char *s)
	:name{nullptr} {
	if (s == nullptr){
		name = new char[1];
		*name = '\0';
	} else {
		name = new char[strlen(s) + 1];
		strcpy(name, s);
	}
}

// Copy constructor
Ferret::Ferret(const Ferret &source)
	:name{nullptr} {
	name = new char[strlen(source.name) + 1];
	strcpy(name, source.name);
	std::cout << "COPY CONSTRUCTOR USED" << std::endl;
}

// Move construcor
Ferret::Ferret(Ferret &&source)
	:name{source.name} {
	source.name = nullptr;
	std::cout << "MOVE CONSTRUCTOR USED" << std::endl;
}

// Destructor
Ferret::~Ferret(){
	delete [] name;
}

// Copy assignment
Ferret &Ferret::operator=(const Ferret &rhs){
	std::cout << "USING COPY ASSIGNMENT" << std::endl;
	
	if(this==&rhs){
		return *this;
	}
	delete [] name;
	name = new char[strlen(rhs.name) + 1];
	strcpy(name, rhs.name);
	return *this;
}

// Move assignment
Ferret &Ferret::operator=(Ferret &&rhs){
	std::cout << "USING MOVE CONSTRUCTOR" << std::endl;
	if(this == &rhs){
		return *this;
	}
	delete [] name;
	name = rhs.name;
	rhs.name = nullptr;
	return *this;
}

// overloade insertion operator
std::ostream &operator<<(std::ostream &os, const Ferret &rhs){
	os << rhs.name;
	return os;
}

// overloaded extraction operator
std::istream &operator>>(std::istream &in, Ferret &rhs){
	char *buff = new char[1000];
	in >> buff;
	rhs = Ferret{buff};
	delete [] buff;
	return in;
}
