#include <iostream>
#include <fstream>
#include <string>

int main(){
	std::string path {};
	std::string data {};
	std::string data2 {};
	std::string data3 {};
	
	std::ifstream in_file;
	std::cout << "Enter File Path/Name: ";
	std::cin >> path;
	in_file.open(path);

	if(!in_file.is_open()){
		std::cerr << "Open file " << path << " failed" << std::endl;
		return 1;
	} else {
		in_file >> data >> data2 >> data3;
		std::cout << "Data => " << data << std::endl;
		std::cout << "Data2 => " << data2 << std::endl;
		std::cout << "Data3 => " << data3 << std::endl;
	}
	
	in_file.close();

	return 0;
}
