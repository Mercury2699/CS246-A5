#ifndef FACTORY_H
#define FACTORY_H
#include <cstdlib>
#include <ctime>

#include "item.h"
#include "potion.h"
#include "player.h"
#include "enemy.h"
#include "treasure.h"
#include "floor.h"
#include "cell.h"

struct Factory {
    Player * spawnPlayer();
    Enemy * genEnemy();
    Potion * genPotion();
    Treasure * genTreasure();
    void genFloor(Floor *);
};


#endif

