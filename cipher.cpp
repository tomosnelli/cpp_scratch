#include <iostream>
#include <string>
#include <cstring>

using namespace std;

int main(){

	const unsigned SHIFT = 5;
	const unsigned LETTER_NUM {26};

	string lower = "abcdefghijklmnopqrstuvwxyz";
	string upper = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	string message {};
	unsigned index {0};

	cout << "-------------Caesar Cipher-------------" << endl;
	cout << "Enter a message to encode: ";
	getline(cin, message);

	cout << "Your message is => " << message << endl;

	for (unsigned i {0}; i < message.length(); ++i){
		if (isupper(message[i])){
			index = upper.find(message[i]);
			message[i] = upper[(index + SHIFT) % LETTER_NUM];
		}
		else if(islower(message[i])){
			index = lower.find(message[i]);
			message[i] = lower[(index + SHIFT) % LETTER_NUM];
		}
		else {
			continue;
		}
	}

	cout << "ciphered message => " << message << endl;

	return 0;
}
