#ifndef CELL_H
#define CELL_H

#include "textDisplay.h"
#include "stuff.h"

class Cell {

	TextDisplay *td;
	Stuff *state;

	public:

	void notifyObserver();
	Stuff *getState();
};
#endif
