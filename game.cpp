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

// foe class
class Foe {
	public:
		int hp {};
		string name;
};


// function prototype
string get_name();
void print_map(vector<int> location);
string get_direction();
int temp_location(string direction, Player& player);
int validate_move(int axis_loc);
void move(string direction, Player& player);
int foe_spawn();
int first_hit();


// main function
int main(){
	// this will be execute the game loop
	string direction {};
	bool valid {};
	// temp location to be tested if valid
	int tmp {0};
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
			// if(validate_move(direction, player)) {move(direction, player)}
			tmp = temp_location(direction, player);
			valid = validate_move(tmp);
			if(valid){
				move(direction, player);
				print_map(player.location);
				if(foe_spawn()){
					cout << "A foe jumped out of the ferns!" << endl;
					cout << "Who goes first?" << endl;
					cout << first_hit() << endl;
					// combat() here. attack will be a helper function to combat.
				}
			}
			else {
				cout << "You hit the wall... Enter valid direction" << endl;
			}
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

int temp_location(string direction, Player& character){
	int destination {0};
	if(direction == "W"){
		destination = character.location.at(0) - 1;
	}
	else if(direction == "S"){
		destination = character.location.at(0) + 1;
	}
	else if(direction == "A"){
		destination = character.location.at(1) - 1;
	}
	else if(direction == "D"){
		destination = character.location.at(1) + 1;
	}
	return destination;
}


// add parameter "Player& player" to access by reference
int validate_move(int axis_loc){
	if((0 <= axis_loc) && (axis_loc < 10)){
		return 1;
	}
	else {
		return 0;
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
	// right
	else if(direction == "D"){
		character.location.at(1) += 1;
	}
}


// chance of foe encouter is defined above
int foe_spawn(){
	const unsigned spawn_rate {0};
	const unsigned MAX {100};
	const unsigned MIN {1};
	srand(time(nullptr));
	if((rand() % MAX + MIN) <= 40){
		return 1;
	}
	else {
		return 0;
	}
}


int first_hit(){

	int player {0};
	int foe {0};

	while(1){
		srand(time(nullptr));
		player = rand() % 100 + 1;
		foe = rand() % 100 + 1;
		if(player > foe){
			return 1;
		}
		else if(foe > player){
			return 0;
		}
		else {
			continue;
		}
	}
}


int combat(Player& character, Foe& foe){
	return 0;
}

void attack(Player& character, Foe& foe){
	return;
}
