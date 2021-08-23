// set up to read one character at a time
// unformatted input. don't need to worry about special characters

#include <iostream>
#include <fstream>
#include <string>

int main(){
	std::ifstream in_file;
	std::string path{};
	char character{};
	std::cout << "Enter File Path/Name: ";
	std::cin >> path;
	in_file.open(path);

	if(!in_file.is_open()){
		std::cerr << "Error opening " << path << std::endl;
		return 1;
	} else {
		while(in_file.get(character)){
			std::cout << character;
		}
		std::cout << std::endl;
	}
	std::cout << "\nOutput with one character at a time done!" << std::endl;

	return 0;
}
