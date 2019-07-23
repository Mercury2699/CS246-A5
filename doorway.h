#ifndef DOORWAY_H
#define DOORWAY_H
#include "cell.h"
#include "stuff.h"

class TextDisplay;

class Doorway final : protected Cell {
    TextDisplay *td = nullptr;
    Stuff * occupant = nullptr;
	bool isOccupied = false;

    public:
    Doorway(int x, int y);
    bool checkOccupancy();
    void setObserver(TextDisplay *);
	void notifyObserver();
	Stuff * getOccupant();
    void attachStuff(Stuff *);
    Stuff* detachStuff();
    char getChar() override;
};

#endif
