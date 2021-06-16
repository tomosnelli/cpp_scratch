#include <iostream>
#include <string>

using namespace std;

class Player {
	public:
		string name;
		int hp;
		unsigned xp;
		Player(string name_val = "None", int hp_val = 50, unsigned xp_val = 0);
		// copy constructor
		Player(const Player &source);
		// destructor
		~Player(){cout << "Destructor called for; " << name << endl;}
};

Player::Player(string name_val, int hp_val, unsigned xp_val)
	:name{name_val}, hp{hp_val}, xp{xp_val} {
		cout << "Three arg constructor for " + name << endl;
}

Player::Player(const Player &source)
	:name{source.name}, hp{source.hp}, xp{source.xp} {
		cout << "copy constructor made copy of: " << source.name << endl;
}

void display_player(Player p){
	// copy will be made in the function
	cout << "Name: " << p.name << endl;
	cout << "Health: " << p.hp << endl;
	cout << "XP: " << p.xp << endl;
}

int main(){
	Player empty;

	display_player(empty);

	Player tom{"TOM"};

	Player new_player_instance {tom};

	return 0;
}
