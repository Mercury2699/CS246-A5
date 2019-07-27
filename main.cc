#include <vector>
#include <string>
#include <iostream>
#include "game.h"

int main(int argc, char *argv[]) {
	std::unique_ptr<Game> g;

	std::string command;
	std::cout << "Welcome to the game of Chamber Crawler 3000+! To start, please select your character:" << std::endl;
	std::cout << "h: Human, e: Elves, d: Dwarf, o: Orc" << std::endl;

	while(std::cin >> command) {
		if(command == "h" || command == "e" || command == "d" || command == "o") {
			if(argc > 1) { // optional command line argument that speficies the layout
				if (std::string(argv[1]) == "-layout") {
					g = std::make_unique<Game>(command, true, argv[2]);
					std::cerr << "Using layout specified by " << argv[2] << std::endl;
				} else if (std::string(argv[1]) == "-map" ){
					g = std::make_unique<Game>(command, argv[2]);
				}
				g = std::make_unique<Game>(command, true, argv[1]);
			} else {
				g = std::make_unique<Game>(command);
			}
			break;
		} else if (command == "q"){
			return 0;
		} else {
			std::cout << "Invalid! Please reselect your character." << std::endl;
		}
	}	
	
	while(std::cin >> command){
		if(command == "r") {
			while(std::cin >> command) {
				if(command == "h" || command == "e" || command == "d" || command == "o") {
					g = std::make_unique<Game>(command);
					break;
				} else {
					std::cout << "Invalid! Please reselect your character." << std::endl;
				}
			}
			continue;
		} else if (command == "q") break;
		int state = g->takeCommand(command);
		if (state == 1) {
			std::cout << "PC is dead!" << std::endl;
			break;
		}
	}
	return 0;
}

