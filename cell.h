#ifndef CELL_H
#define CELL_H
#include "textDisplay.h"
#include "stuff.h"

class Cell {
	const int x, y;
	TextDisplay *td;
	bool isOccupied;
	Stuff * occupant;
	
	public:
	Cell(TextDisplay *, int, int);
	virtual char getState() = 0;
	int getX();
	int getY();
	bool checkOccupancy();
	void notifyObserver();
	Stuff * getOccupant();
};
#endif

