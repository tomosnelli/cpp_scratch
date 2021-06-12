#include <iostream>
#include <string>

using namespace std;

class Player {
	public:
		string name;
		unsigned hp;
		unsigned xp;
		// delegate constructors
		Player()
			:Player{"None", 0, 0}{
			cout << "no constructor parameters passed" << endl;
		}

		Player(string name_val)
			:Player{name_val, 0, 0}{
			cout << "Name constructor parameter passed" << endl;
		}

		Player(string name_val, unsigned hp_val, unsigned xp_val)
			:name{name_val}, hp{hp_val}, xp{xp_val}{
		}
};

int main(){
	Player tom;
	Player kaneko {"Tomo", 100, 0};

	cout << kaneko.name << " " << kaneko.hp << " " << kaneko.xp << endl;
	
	return 0;
}
