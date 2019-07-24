#ifndef CELL_H
#define CELL_H

#include "stuff.h"
class TextDisplay;

struct Cell {
	int x = 0, y = 0;
	bool isOccupied = false;
	Stuff *occupant = nullptr;
	TextDisplay *td = nullptr;

	public:
    Cell(int x, int y);
	virtual char getChar() = 0;
    virtual bool checkOccupancy() { return (isOccupied && occupant); }
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
	);

	protected:
	void setOccupancy(bool occupied) { isOccupied = occupied; };
	TextDisplay *getTD(){ return td; };
};


#endif
