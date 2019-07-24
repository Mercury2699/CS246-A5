#ifndef ITEM_H
#define ITEM_H

#include "stuff.h"

class Player;


class Item : public Stuff {
	void virtual effect(Player &pc) = 0;
};



#endif
