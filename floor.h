#ifndef FLOOR_H
#define FLOOR_H

#include <vector>
#include <iostream>
#include <string>
#include <memory>
#include "cell.h"
#include "textDisplay.h"

class TextDisplay;

class Floor {
	std::vector<std::vector<std::shared_ptr<Cell>>> theGrid;
	TextDisplay * td;
	public:
	void startGame(std::string race);
	void playerMove(std::string direction);
	void playerAtk(std::string direction);
	void playerUse(std::string direction);
	void moveEnemies();

	
	Floor(std::string file = "map.txt");
	friend std::ostream &operator<<(std::ostream &out, const Floor &f);
};

#endif
