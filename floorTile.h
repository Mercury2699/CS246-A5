#ifndef FLOORTILE_H
#define FLOORTILE_H
#include "cell.h"
#include "stuff.h"

class TextDisplay;


class FloorTile final : protected Cell {
    TextDisplay *td = nullptr;
    Stuff * occupant = nullptr;
	bool isOccupied = false;

    public:
    FloorTile(int x, int y);
    bool checkOccupancy();
    void setObserver(TextDisplay *);
	void notifyObserver();
	Stuff * getOccupant();
    void attachStuff(Stuff *);
    Stuff* detachStuff();
    
    char getChar() override;
};
#endif
