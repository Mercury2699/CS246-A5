#include <vector>
#include <string>
#include <iostream>
#include "textDisplay.h"
#include "floor.h"

const std::string N = "no", S = "so", E = "ea", W = "we", NE = "ne", NW = "nw", SE = "se", SW = "sw";
const std::string UseN = "u<no>", UseS = "u<so>", UseE = "u<ea>", UseW = "u<we>";
const std::string UseNE = "u<ne>", UseNW = "u<nw>", UseSE = "u<se>", UseSW = "u<sw>";
const std::string AtkN = "a<no>", AtkS = "a<so>", AtkE = "a<ea>", AtkW = "a<we>";
const std::string AtkNE = "a<ne>", AtkNW = "a<nw>", AtkSE = "a<se>", AtkSW = "a<sw>";

int main(int argc, char *argv[]) {
	std::vector<Floor> floors;
	TextDisplay td;
	std::string command;
	std::cout << "Welcome to the game of Chamber Crawler 3000+! To start, please select your character:" << std::endl;
	std::cout << "h: Human, e: Elves, d: Dwarf, o: Orc" << std::endl;
	std::cin >> command;
	if(command == "h") {
		// spawn human player
	} else if (command == "e"){
		// elves
	} else if (command == "d"){
		// dwarf
	} else if (command == "o"){
		// orc
	}
	while(1){
		std::cin >> command;
		//if command is valid...
		if (command == "q") {
			break;
		}
		std::cout << td;
	}
	return 0;
}
