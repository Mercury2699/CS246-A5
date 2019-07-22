#include <vector>
#include <iostream>
#include "textDisplay.h"
#include "factory.h"

using namespace std;

const string N = "no", S = "so", E = "ea", W = "we", NE = "ne", NW = "nw", SE = "se", SW = "sw";
const string UseN = "u<no>", UseS = "u<so>", UseE = "u<ea>", UseW = "u<we>";
const string UseNE = "u<ne>", UseNW = "u<nw>", UseSE = "u<se>", UseSW = "u<sw>";
const string AtkN = "a<no>", AtkS = "a<so>", AtkE = "a<ea>", AtkW = "a<we>";
const string AtkNE = "a<ne>", AtkNW = "a<nw>", AtkSE = "a<se>", AtkSW = "a<sw>";

int main(int argc, char *argv[]) {
	vector<Floor> floors;
	TextDisplay td;
	Factory f;
	string command;
	cout << "Welcome to the game of Chamber Crawler 3000+! To start, please select your character:" << endl;
	cout << "h: Human, e: Elves, d: Dwarf, o: Orc" << endl;
	cin >> command;
	if(command == "h") {
		// spawn human player
	} else if (command == "e"){
		// elves
	} else if (command == "d"){
		// dwarf
	} else if (command == "o"){
		// orc
	}
	floors[0];
	while(1){
		cin >> command;
		//if command is valid...
	}
	return 0;
}
