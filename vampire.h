#ifndef VAMPIRE_H
#define VAMPIRE_H
#include "enemy.h"

class Vampire : public Enemy {
  public:
  Vampire(Treasure *t) : Enemy{50, 25, 25, t} {}
	char getChar() override;
};


#endif
