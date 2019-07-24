#ifndef TREASURE_H
#define TREASURE_H

#include "item.h"

class Treasure : public Item {
	int val;

	public:
	int getValue();
	char getChar() override {return 'G';}
};



#endif


