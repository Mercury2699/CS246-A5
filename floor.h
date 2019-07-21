#ifndef FLOOR_H
#define FLOOR_H

#include <vector>
#include <iostream>

class Floor {
	std::vector<std::vector<Cell*>> cells;

};

std::ostream &operator<<(std::ostream &out, const Floor &f);
#endif
