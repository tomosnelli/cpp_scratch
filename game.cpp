/*
Name: tomosnelli
Description: A3 assignment remake attempt with cpp
*/

#include <iostream>
#include <string>
#include <vector>

using namespace std;

// constants? need to learn more about how to place them where.
// player constants
const int INIT_HP {50};
const unsigned INIT_ATTACK {20};
const unsigned HIT_RATE {80};

// foe constants
const int FOE_HP {30};
const unsigned FOE_ATTACK {10};
const unsigned FOE_HIT_RATE {75};

// board constraints
const unsigned WIDTH {10};
const unsigned HEIGHT {10};


// player class
class Player {
	public:
		int hp {INIT_HP};
		string name;
		vector<int> location {0, 0};
		// constructor
		Player(string input_name){
			name = input_name;
		}
};


// function prototype
string get_name();
void print_map(vector<int> location);
string get_direction();
void move(string direction, Player& player);


// main function
int main(){
	// this will be execute the game loop
	string direction {};
	string name = get_name();
	Player player(name);

	print_map(player.location);
	while(1){
		direction = get_direction();
		if(direction == "q"){
			break;
		}
		else {
			// validate direction....
			move(direction, player);
			cout << player.location.at(0) << " and " << player.location.at(1) << endl;
			print_map(player.location);
		}
	}

	return 0;
}


// functions
string get_name(){
	string name {};
	while(true){
		cout << "What is your name? => ";
		getline(cin, name);
		if(name.length() > 0){
			return name;
		}
		else {
			cout << "Invalid name. Enter again" << endl;
		}
	}
}


void print_map(vector<int> location){
	for(unsigned i {0}; i < HEIGHT; ++i){
		for(unsigned j {0}; j < WIDTH; ++j){
			// 0 is x axis and 1 is y axis
			if(location.at(0) == i and location.at(1) == j){
				cout << "🤺";
			}
			else {
				cout << " .";
			}
		}
		cout << endl;
	}
}


string get_direction(){
	cout << "Enter direction you want to go with W, A, S, D" << endl;
	string direction {};
	getline(cin, direction);
	return direction;
}

bool validate_move(int axis_loc){
	if(0 <= axis_loc < 10){
		return true;
	}
	else {
		return false;
	}
}

void move(string direction, Player& character){
	// up
	if(direction == "W"){
		character.location.at(0) -= 1;
	}
	// down
	else if(direction == "S"){
		character.location.at(0) += 1;
	}
	// left
	else if(direction == "A"){
		character.location.at(1) -= 1;
	}
	else if(direction == "D"){
		character.location.at(1) += 1;
	}
	cout << character.location.at(0) << ", " << character.location.at(1) << endl;
}
