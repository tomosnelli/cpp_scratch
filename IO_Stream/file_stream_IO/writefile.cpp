#include <iostream>
#include <fstream>
#include <string>

// when I try to take input for the file name, it causes errors when taking
// input for the file content. Seems like path's null character might be
// interfering with the getline in line 20.
// maybe use a force flush with the code in taking the path name?

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
