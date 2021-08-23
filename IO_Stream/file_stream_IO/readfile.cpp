#include <iostream>
#include <fstream>
#include <string>

int main(){
	std::fstream in_file;
	std::string line;
	int num;
	std::string line2;
	
	in_file.open("test.txt");

	if(!in_file.is_open()){
		std::cerr << "Open file test.txt failed" << std::endl;
		return 1;
	} else {
		std::cout << "Opened file test.txt" << std::endl;
	}

	in_file >> line >> num >> line2;
	std::cout << line << num << line2 << std::endl;

	in_file.close();

	return 0;
}
