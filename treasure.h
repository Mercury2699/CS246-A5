#ifndef TREASURE_H
#define TREASURE_H
#include "item.h"

class Treasure : public Item {
	public:
	virtual int getValue() = 0;
};
#endif
