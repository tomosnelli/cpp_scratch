#include <iostream>

using namespace std;

class Shallow {
	private:
		int *data;
	public:
		void set_data_value(int d){ *data = d; }
		int get_data_value(){return *data;}
		// constructor
		Shallow(int d);
		// copy constructor
		Shallow(const Shallow &source);
		// destructor
		~Shallow();
}

Shallow::Shallow(int d){
	data = new int;
	*data = d;
}

Shallow::Shallow(const Shallow &source)
	:data(source.data){
		// this will have the same view?
		cout << "Copy constructor -shallow copy" << endl;
}

Shallow::~Shallow(){
	delete data;
	cout << "Destructor freeing memory on heap" << endl;
}

int main(){

}
