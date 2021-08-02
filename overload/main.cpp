#include <iostream>
#include "Ferret.h"

using namespace std;

int main(){
	Ferret hail{"Hail"};
	Ferret snow{"Snow"};
	Ferret ferret;

	cout << "Enter a ferret name: ";
	cin >> ferret;

	cout << "/nEnter three ferret names separated by a space: ";
	cin >> hail >> snow >> ferret;

	cout << "The three ferrets are => " << hail << ", " << snow << ", " << ferret << endl;
	return 0;
}
