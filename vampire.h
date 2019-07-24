#ifndef VAMPIRE_H
#define VAMPIRE_H
#include "enemy.h"

class Vampire : public Enemy {
  public:
  Varmpire(Treasure *t) {50, 25, 25, t}{}
};
#endif
