#ifndef FLOOR_H
#define FLOOR_H

#include <vector>
#include <iostream>
#include "cell.h"

class Floor {
	std::vector<std::vector<Cell*>> cells;

	friend std::ostream &operator<<(std::ostream &out, const Floor &f);
};

#endif
