#ifndef PASS_H
#define PASS_H
#include "cell.h"

class Passage : public Cell {
    TextDisplay *td = nullptr;
	bool isOccupied;
	Stuff * occupant;

    public:
    Passage(int x, int y) : Cell{x,y} {}
    bool checkOccupancy() override;
	void notifyObserver() override;
	Stuff * getOccupant() override;
    char getState() override;
};

#endif
