#ifndef _FERRET_H_
#define _FERRET_H_

class Ferret{

	// prototypes here for << >>
	friend std::ostream &operator<<(std::ostream &os, const Ferret &rhs);
	friend std::istream &operator>>(std::istream &in, Ferret &rhs);

	private:
		char *name;
	public:
		Ferret();						// No-args constructor
		Ferret(const char *s);			// Overloaded constructor
		Ferret(const Ferret &source);	// Copy constructor
		Ferret(Ferret &&source);		// Move constructor
		~Ferret();						// Destructor

		Ferret &operator=(const Ferret &rhs);	// Copy assignment
		Ferret &operator=(Ferret &&rhs);		// Move assignment
};

#endif // _FERRET_H_
