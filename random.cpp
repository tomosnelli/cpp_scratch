#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;

int main(){

	int rand_num {};
	size_t count {10};
	const unsigned min {1};
	const unsigned max {6};

	cout << "RAND_MAX on my systems => " << RAND_MAX <<endl;
	srand(time(nullptr));

	for (size_t i {1}; i <= count; ++i){
		rand_num = rand() % max + min;
		cout << rand_num << endl;
	}

	cout << endl;

	return 0;
}
