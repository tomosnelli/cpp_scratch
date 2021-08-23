#include <iostream>
#include <fstream>

int main(){
	std::fstream in_file;
	in_file.open("test.txt");

	if(!in_file.is_open()){
		std::cerr << "Open file test.txt failed" << std::endl;
		return 1;
	} else {
		std::cout << "Opened file test.txt" << std::endl;
	}

	in_file.close();

	return 0;
}
