#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;

void print(vector<int> param);

int main(){

	vector<int> my_vector(10, 10);
	
	print(my_vector);

	return 0;
}

void print(vector<int> param){
	for(int i: param){
		cout << i << endl;
	}
	return;
}

