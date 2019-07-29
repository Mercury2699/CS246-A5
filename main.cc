#include <vector>
#include <string>
#include <iostream>
#include <ncurses.h>
#include "game.h"

const char restart = 'r', quit = 'q';

int main(int argc, char *argv[]) {
	initscr(); // Ncurses initializations
    clear(); // clear screen
    noecho(); // suppress the automatic echoing of typed characters
    cbreak(); // disable the buffering of typed characters
    keypad(stdscr, TRUE); // to capture special keystrokes like arrow keys
    curs_set(0);

	std::unique_ptr<Game> g;
	char cmd;
	std::string command;
	std::cout << "Welcome to the game of Chamber Crawler 3000+!" << std::endl;
	std::cout << " To start, please select your character:" << std::endl;
	std::cout << "h: Human, e: Elves, d: Dwarf, o: Orc" << std::endl;
	
	while(1) {
		cmd = getch();
		if(cmd == 'h' || cmd == 'e' || cmd == 'd' || cmd == 'o') {
			if(argc > 1) { // optional command line argument that speficies the layout
				if (std::string(argv[1]) == "-layout") {
					g = std::make_unique<Game>(cmd, true, argv[2]);
					// std::cerr << "Using layout specified by " << argv[2] << std::endl;
				} else if (std::string(argv[1]) == "-map" ){
					g = std::make_unique<Game>(cmd, argv[2]);
				}
			} else {
				g = std::make_unique<Game>(cmd);
			}
			break;
		} else if (cmd == quit){
			clear();
        	endwin();
			return 0;
		} else {
			std::cout << "Invalid! Please reselect your character." << std::endl;
		}
	}	
	
	while(1){
		cmd = getch();
		if(cmd == restart) {
			std::cout << "To restart, please select your character:" << std::endl;
			std::cout << "h: Human, e: Elves, d: Dwarf, o: Orc" << std::endl;
			while(1) {
				cmd = getch();
				if(cmd == 'h' || cmd == 'e' || cmd == 'd' || cmd == 'o') {
					g = std::make_unique<Game>(cmd);
					break;
				} else {
					std::cout << "Invalid! Please reselect your character." << std::endl;
				}
			}
			continue;
		} else if (cmd == quit) {
			clear();
        	endwin();
			break;
		}
		int state = g->takeCommand();
		if (state == 1) {
			break;
		}
	}
	return 0;
}

