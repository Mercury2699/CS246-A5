#ifndef WALL_H
#define WALL_H
#include "cell.h"

 class Wall final : public Cell{
     bool isHorizontal;

    // protected:
	// int x = 0, y = 0; inherited from Cell
	// bool isOccupied = false; inherited from Cell
	// Stuff *occupant = nullptr; inherited from Cell
	// TextDisplay *td = nullptr; inherited from Cell
    
    public:
    Wall(int x, int y, bool isHor) : Cell{x, y}, isHorizontal{isHor} {
        setOccupancy(true);
    }
    bool checkOccupancy(bool forEnemy) const override { return true; } // inherited from Cell
    char getChar() const override {
        if (isHorizontal) return '-';
        return '|';
    } // inherited from Cell
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



