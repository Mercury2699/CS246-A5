#ifndef CELL_H
#define CELL_H

#include <memory>
#include "stuff.h"
#include "textDisplay.h"

class Cell {
	protected:
	int x = 0, y = 0;
	bool isOccupied = false;
	std::shared_ptr<Stuff> occupant = nullptr;
	std::shared_ptr<TextDisplay> td = nullptr;

	public:
    Cell(int x, int y) : x{x}, y{y} {}
	virtual ~Cell() = default;
	virtual char getChar() const = 0;
    virtual bool checkOccupancy() const {
		return isOccupied;
	}
    void setObserver(std::shared_ptr<TextDisplay> td) { this->td = td;};
	void notifyObserver() { td->notify(x,y,getChar()); };
	
	std::shared_ptr<Stuff> getOccupant() { return occupant; };

    void attachStuff(std::shared_ptr<Stuff> s) { 
		isOccupied = true;
    	occupant = s;
    	notifyObserver(); 
	};

    std::shared_ptr<Stuff> detachStuff() {
		std::shared_ptr<Stuff> temp = occupant;
    	isOccupied = false;
    	occupant = nullptr;
    	notifyObserver();
   		return temp;
	};
	/* setOccupancy should be used to set occupancy when attaching 
	 * items that can be stepped on, e.g. Treasure and floor
	 */
	void setOccupancy(bool occupied) {
		isOccupied = occupied; 
		notifyObserver();
	};

	int getX() const {return x;}
	int getY() const {return y;}
	};


#endif
