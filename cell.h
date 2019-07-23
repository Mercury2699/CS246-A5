#ifndef CELL_H
#define CELL_H
#include "textDisplay.h"

class TextDisplay;

struct Cell {
	int x = 0, y = 0;
	virtual char getChar() = 0;
};


#endif



