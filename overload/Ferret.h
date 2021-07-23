#include <string>

class Ferret{
	private:
		char *name;					// raw C pointer
	public:
		// constructor
		Ferret(const Ferret &source)		// pass by reference
		void display() const;
		Ferret operator-() const;	// make lowercase
		Ferret operator+(const Ferret &rhs);	// cat to name
		bool operator==(const Ferret &rhs);		// equal overload
};
