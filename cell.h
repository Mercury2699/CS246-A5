#ifndef CELL_H
#define CELL_H
#include "textDisplay.h"

class TextDisplay;
struct Stuff;

class Cell {
	protected:
	const int x, y;
	// bool isOccupied;
	// Stuff * occupant;
	
	public:
	Cell(int x, int y) : x{x}, y{y} {}
	virtual char getState() = 0;
	int getX() {return x;}
	int getY() {return y;}
	virtual bool checkOccupancy() = 0;
	virtual void notifyObserver() = 0;
	virtual Stuff * getOccupant() = 0;
};
#endif

