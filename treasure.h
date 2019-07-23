#ifndef TREASURE_H
#define TREASURE_H

#include "item.h"

class Treasure : public Item {
	protected:
	int val;

	public:
	virtual int getValue() = 0;
	char getChar() override {return 'G';}
};



#endif


