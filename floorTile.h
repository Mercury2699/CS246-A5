#ifndef FLOORTILE_H
#define FLOORTILE_H
#include "cell.h"

class FloorTile : public Cell {
    TextDisplay *td = nullptr;
	bool isOccupied;
	Stuff * occupant;

    public:
    FloorTile(TextDisplay * td, int x, int y) : Cell{x, y} {}
    bool checkOccupancy();
	void notifyObserver();
	Stuff * getOccupant();
    char getState() override {
        if(checkOccupancy())
            return getOccupant()->getState();
        return '.';
    }
};
#endif
