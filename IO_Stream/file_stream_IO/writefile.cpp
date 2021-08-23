#include <iostream>
#include <fstream>
#include <string>

int main(){
	std::string path {"test.txt"};
	std::string input {};

	std::ofstream out_file{path};

	if(!out_file){
		std::cerr << "Error creating file " << path << std::endl;
	} else {
		
		while(1){
			std::cout << "Enter text to write to file: ";
			std::getline(std::cin, input);
			if(input == "q"){
				break;
			}
			out_file << input << std::endl;
		}
	}

	out_file.close();
	
	return 0;
}
