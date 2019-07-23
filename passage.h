#ifndef PASS_H
#define PASS_H
#include "cell.h"

class TextDisplay;
struct Stuff;

class Passage final : protected Cell {
    TextDisplay *td = nullptr;
    Stuff * occupant = nullptr;
	bool isOccupied = false;

    public:
    Passage(int x, int y);
    bool checkOccupancy();
    void setObserver(TextDisplay *);
	void notifyObserver();
	Stuff * getOccupant();
    char getChar() override;
};

#endif

