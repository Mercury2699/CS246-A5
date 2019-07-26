#ifndef EMPTYCELL_H
#define EMPTYCELL_H
#include "cell.h"

struct EmptyCell final : public Cell {
    // protected:
	// int x = 0, y = 0; inherited from Cell
	// bool isOccupied = false; inherited from Cell
	// Stuff *occupant = nullptr; inherited from Cell
	// TextDisplay *td = nullptr; inherited from Cell
    public: 
    EmptyCell(int x, int y) : Cell{x, y} {
        isOccupied = true;
    }
    char getChar() const override {return ' ';} // inherited from Cell
    bool checkOccupancy() const override { return true;} // inherited from Cell
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

