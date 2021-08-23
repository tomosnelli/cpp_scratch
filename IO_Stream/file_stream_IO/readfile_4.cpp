#include <iostream>
#include <fstream>
#include <string>

int main(){
	std::ifstream in_file;
	std::string path{};
	std::string line{};
	std::cout << "Enter Path/Name: " << std::endl;
	std::cin >> path;

	in_file.open(path);
	if(!in_file.is_open()){
		std::cerr << "Error opening " << path << std::endl;
		return 1;
	} else {
		while(std::getline(in_file, line)){
			std::cout << line << std::endl;
		}
	}

	return 0;
}
