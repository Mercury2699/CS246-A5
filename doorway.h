#ifndef DOORWAY_H
#define DOORWAY_H
#include "cell.h"

class Doorway : public Cell {
    TextDisplay *td = nullptr;
	bool isOccupied;
	Stuff * occupant;

    public:
    Doorway(int x, int y) : Cell{x, y} {}
    bool checkOccupancy() override;
	void notifyObserver() override;
	Stuff * getOccupant() override;
    char getState() override;
};

#endif
