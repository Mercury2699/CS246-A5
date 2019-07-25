#include <vector>
#include <string>
#include <iostream>
#include "game.h"

int main(int argc, char *argv[]) {
	Game g;
	if(argc > 1) {
		
	} 
	
	std::string command;
	
	std::cout << "Welcome to the game of Chamber Crawler 3000+! To start, please select your character:" << std::endl;
	std::cout << "h: Human, e: Elves, d: Dwarf, o: Orc" << std::endl;
	std::cin >> command;
	if(command == "h" || command == "e" || command == "d" || command == "o") {
		g->startGame(command);
	} else {
		std::cout << "Invalid! Please reselect your character." << std::endl;
	}
	while(1){
		std::cin >> command;
		if(command == "r") {
			g->resetGame();
			break;
		} else if (command == "q") break;
		g->takeCommand(command);
	}
	return 0;
}
