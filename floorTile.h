#ifndef FLOORTILE_H
#define FLOORTILE_H
#include "cell.h"
class TextDisplay;
struct Stuff;

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
    
    char getChar() override;
};
#endif
