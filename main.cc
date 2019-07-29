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

	mvprintw(0, 0, "%s", "Welcome to the game of Chamber Crawler 3000+!");
	mvprintw(1, 0, "%s", "To start, please select your character:");
	mvprintw(2, 0, "%s", "h: Human 140 HP, 20 Atk, 20 Def, +50% score");
	mvprintw(3, 0, "%s", "e: Elves 140 HP, 30 Atk, 10 Def, negative potions have positive effect");
	mvprintw(4, 0, "%s", "d: Dwarf 100 HP, 20 Atk, 30 Def, gold is doubled in value");
	mvprintw(5, 0, "%s", "o: Orc   180 HP, 30 Atk, 25 Def, gold is worth half value");
	
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
			mvprintw(6, 0, "%s", "Invalid! Please reselect your character.");
		}
	}	
	
	while(1){
		cmd = getch();
		if(cmd == restart) {
			mvprintw(0, 0, "%s", "To restart, please select your character:");
			mvprintw(1, 0, "%s", "h: Human 140 HP, 20 Atk, 20 Def, +50% score");
			mvprintw(2, 0, "%s", "e: Elves 140 HP, 30 Atk, 10 Def, negative potions have positive effect");
			mvprintw(3, 0, "%s", "d: Dwarf 100 HP, 20 Atk, 30 Def, gold is doubled in value");
			mvprintw(4, 0, "%s", "o: Orc   180 HP, 30 Atk, 25 Def, gold is worth half value");
			while(1) {
				cmd = getch();
				if(cmd == 'h' || cmd == 'e' || cmd == 'd' || cmd == 'o') {
					g = std::make_unique<Game>(cmd);
					break;
				} else {
					mvprintw(5, 0, "%s", "Invalid! Please reselect your character.");
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
	clear();
	endwin();
	return 0;
}

