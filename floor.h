#ifndef FLOOR_H
#define FLOOR_H

#include <vector>
#include <iostream>
#include <string>
#include <memory>
#include "cell.h"
#include "textDisplay.h"

class TextDisplay;
class Cell;

class Floor {
	std::vector<std::vector<std::shared_ptr<Cell>>> theGrid;
	TextDisplay * td;
	public:
	Floor(std::string file = "map.txt");
	friend std::ostream &operator<<(std::ostream &out, const Floor &f);
};

#endif
