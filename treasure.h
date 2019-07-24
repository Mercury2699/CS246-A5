#ifndef TREASURE_H
#define TREASURE_H

#include "item.h"

class Treasure : public Item {
	int val;

	public: 
	Treasure(int val): val{val} {}
	int getValue() { return val; }
	char getChar() override {return 'G';}
};



#endif


