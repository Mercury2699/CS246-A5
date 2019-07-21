#ifndef CELL_H
#define CELL_H

class Cell {

	TextDisplay *td;
	char state;
	
	public:

	void notifyObserver();
	char getState();
};
#endif
