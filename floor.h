#ifndef FLOOR_H
#define FLOOR_H

#include <vector>
#include <iostream>
#include <string>
#include "cell.h"

class Cell;

class Floor {
	std::vector<std::vector<Cell*>> cells;
	TextDisplay * td;

	void init(std::string file = "map.txt");
	friend std::ostream &operator<<(std::ostream &out, const Floor &f);
};

#endif
