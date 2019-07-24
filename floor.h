#ifndef FLOOR_H
#define FLOOR_H

#include <vector>
#include <iostream>
#include <string>
#include <memory>
#include <cmath>
#include "cell.h"
#include "textDisplay.h"
#include "player.h"
class TextDisplay;

class Floor {
	std::vector<std::vector<std::shared_ptr<Cell>>> theGrid;
	TextDisplay * td = nullptr;
	Player *pc;
	std::vector<std::shared_ptr<Cell>> enemies;

	public:
	void startGame(std::string race);
	void playerMove(std::string direction);
	void playerAtk(std::string direction);
	void playerUse(std::string direction);
	void moveEnemies();
	void checkEvents(Cell *);
	Cell *target(Cell *cur, std::string direction);

	void setObserver(TextDisplay *td);


	
	Floor(std::string file = "map.txt");
	friend std::ostream &operator<<(std::ostream &out, const Floor &f);
};

#endif
