#ifndef VAMPIRE_H
#define VAMPIRE_H
#include "enemy.h"

class Vampire : public Enemy {
  	public:
  	Vampire(Item *i) : Enemy{50, 25, 25, i} {}
	char getChar() const override;
};


#endif
