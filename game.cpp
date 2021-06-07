/*
Name: tomosnelli
Description: A3 assignment remake attempt with cpp
*/

#include <iostream>
#include <string>
#include <vector>
#include <chrono>
#include <thread>

using namespace std;

// constants? need to learn more about how to place them where.
// player constants
const int INIT_HP {50};
const unsigned INIT_ATTACK {20};
const unsigned HIT_RATE {80};

// foe constants
const int FOE_HP {30};
const unsigned FOE_ATTACK {5};
const unsigned FOE_HIT_RATE {75};

// board constraints
const unsigned WIDTH {10};
const unsigned HEIGHT {10};


// player class
class Player {
	public:
		int hp {INIT_HP};
		unsigned attack {INIT_ATTACK};
		string name;
		vector<int> location {0, 0};
		// constructor
		Player(string input_name, int input_hp = INIT_HP, unsigned input_attack = INIT_ATTACK){
			name = input_name;
			hp = input_hp;
			attack = input_attack;
		}
};

// foe class will reuse the player class. This is needed to be done
// for some functions for my approch

// function prototype
string get_name();
void print_map(vector<int> location);
string get_direction();
int temp_location(string direction, Player& player);
int validate_move(int axis_loc);
void move(string direction, Player& player);
int foe_spawn();
string foe_name();
int first_hit();
int combat(Player& character, Player& foe, int goes_first);
int death_check(Player& character, Player& foe);
void heal(Player& character);


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
				if(player.location.at(0) == 9 && player.location.at(1) == 9){
					cout << "You reached the goal!" << endl;
					break;
				}
				if(foe_spawn()){
					cout << "A " << foe_name() << " jumped out of the ferns!" << endl;
					Player foe(foe_name(), FOE_HP, FOE_ATTACK);
					int who_hit_first {first_hit()};
					combat(player, foe, who_hit_first);
					if(death_check(player, foe)){
						cout << "You have been defeated..." << endl;
						break;	
					}
					cout << player.hp << " <= player hp" << endl;
					cout << foe.hp << " <= foe.hp" << endl;
				}
				else {
					heal(player);
				}
			}
			else {
				cout << "You hit a wall... Enter valid direction" << endl;
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
	if((rand() % MAX + MIN) <= 30){
		return 1;
	}
	else {
		return 0;
	}
}


string foe_name(){
	vector<string> foe_name {"wild bore", "bear", "tiger", "moose", "bat"};
	srand(time(nullptr));
	return foe_name.at(rand() % 4 + 0);
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


void heal(Player& character){
	if(character.hp > 40){
		character.hp = INIT_HP;
	}
	else {
		character.hp += 10;
	}
}


void flee(){
	
}


void attack(Player& first, Player& second){
	second.hp -= first.attack;
	if(second.hp < 0){
		second.hp = 0;
	}
	this_thread::sleep_for(chrono::milliseconds(2000));
	cout << first.name << " delt " << first.attack << " damage!" << endl; 
	return;
}


int combat(Player& character, Player& foe, int goes_first){
	if(goes_first){
		cout << "You hit first!" << endl;
	}
	else {
		cout << foe.name << " hits first!" << endl;
	}

	while((character.hp > 0)&&(foe.hp > 0)){
		if(goes_first){
			attack(character, foe);
			if(death_check(character, foe)){ break; }
			attack(foe, character);
		}
		else {
			attack(foe, character);
			if(death_check(character, foe)){ break; }
			attack(character, foe);
		}
	}
	
	return 0;
}


int death_check(Player& character, Player& foe){
	if(character.hp <= 0){
		return true;
	}
	else if(foe.hp <= 0){
		return false;
	}
	return EXIT_SUCCESS;
}
