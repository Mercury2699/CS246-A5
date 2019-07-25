#ifndef PASS_H
#define PASS_H
#include "cell.h"
#include "stuff.h"

class TextDisplay;

class Passage final : public Cell {
    // protected:
	// int x = 0, y = 0; inherited from Cell
	// bool isOccupied = false; inherited from Cell
	// Stuff *occupant = nullptr; inherited from Cell
	// TextDisplay *td = nullptr; inherited from Cell

    public:
    Passage(int x, int y);
    char getChar() const override; // inherited from Cell
    bool checkOccupancy() const override;
    // void setObserver(TextDisplay *td) { this->td = td;}; inherited from Cell
	// void notifyObserver() { td->notify(x,y,getChar()); }; inherited from Cell
    // Stuff * getOccupant(); inherited from Cell
    // Stuff* detachStuff(); inherited from Cell
    // void setOccupancy; inherited from Cell
	// void setOccupant; inherited from Cell
	// int getX() const; inherited from Cell
	// int getY() const; inherited from Cell
};

#endif

