#ifndef HUMAN_H
#define HUMAN_H

#include "player.h"
class Human : public Player {

	public:
	Human(int HP = 140, int Atk = 20, int Def = 20, double treasure = 0);
	
};

#endif
