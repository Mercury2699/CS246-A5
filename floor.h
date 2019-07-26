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
	std::vector<std::shared_ptr<Cell>> floorTiles;
	std::vector<std::vector<std::shared_ptr<Cell>>> chambers;
	Player * pc = nullptr;
	TextDisplay * td;
	
	public:
	Floor(std::string file = "map.txt");
	Floor(std::ifstream &fs);
	void playerMove(std::string direction);
	void playerAtk(std::string direction);
	void playerUse(std::string direction);
	void moveEnemies();
	int checkEvents();
	void setTD(TextDisplay *);
	void setPC(Player *);
	std::shared_ptr<Cell> getCellPC();
	std::shared_ptr<Cell> target(std::shared_ptr<Cell> cur, std::string direction);
	bool setCell(std::shared_ptr<Cell> c, std::shared_ptr<Stuff> s);
	std::shared_ptr<Player> getPlayer();
	std::vector<std::shared_ptr<Cell>> getTiles();
	std::vector<std::vector<std::shared_ptr<Cell>>> getChambers();

	friend std::ostream &operator<<(std::ostream &out, const Floor &f);
};

#endif
