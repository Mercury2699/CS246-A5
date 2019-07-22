#ifndef CELL_H
#define CELL_H
#include "textDisplay.h"

class TextDisplay;
struct Stuff;

class Cell {
	const int x, y;
	// bool isOccupied;
	// Stuff * occupant;
	
	public:
	Cell(int, int);
	virtual char getState() = 0;
	int getX();
	int getY();
	bool checkOccupancy();
	void notifyObserver();
	Stuff * getOccupant();
};
#endif

