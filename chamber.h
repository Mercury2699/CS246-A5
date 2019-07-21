#ifndef CHAMBER_H
#define CHAMBER_H

#include <vector>
#include "cell.h"

class Chamber {
	std::vector<std::vector<Cell*>> cells;
};

#endif
