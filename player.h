#ifndef PLAYER_H
#define PLAYER_H

#include "character.h"

class Player : public Character {

	int gold;

	public:
	Player(int gold);
	void virtual setGold(int gold) = 0;
	void virtual applyPotion(Potion *p) = 0;
	

};
#endif
