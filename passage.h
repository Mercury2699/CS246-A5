#ifndef PASS_H
#define PASS_H
#include "cell.h"

class Passage : public Cell {
    TextDisplay *td = nullptr;
	bool isOccupied;
	Stuff * occupant;

    public:
    Passage(int x, int y) : Cell{x,y} {}
    bool checkOccupancy();
	void notifyObserver();
	Stuff * getOccupant();
    char getState() override { return '#';}
};
#endif
