#ifndef CELL_H
#define CELL_H

#include "stuff.h"
#include "textDisplay.h"

class Cell {
	protected:
	int x = 0, y = 0;
	bool isOccupied = false;
	Stuff *occupant = nullptr;
	TextDisplay *td = nullptr;

	public:
    Cell(int x, int y);
	virtual char getChar() const = 0;
    virtual bool checkOccupancy() const { return isOccupied; }
    void setObserver(TextDisplay *td) { this->td = td;};
	void notifyObserver() { td->notify(x,y,getChar()); };
	
	Stuff * getOccupant() { return occupant; };
    void attachStuff(Stuff *s) { 
		isOccupied = true;
    	occupant = s;
    	notifyObserver(); 
	};

    Stuff* detachStuff() {
		Stuff *temp = occupant;
    	isOccupied = false;
    	occupant = nullptr;
    	notifyObserver();
   		return temp;
	};
	void setOccupancy(bool occupied) { isOccupied = occupied; };
	void setOccupant(Stuff *occupant) { this->occupant = occupant; };
	int getX() const {return x;}
	int getY() const {return y;}
	// void setX(int x) {this->x = x;}
	// void setY(int y) {this->y = y;}
	};


#endif
