#ifndef FACTORY_H
#define FACTORY_H
#include <cstdlib>
#include <ctime>
#include "character.h"
#include "player.h"

#include "enemy.h"
#include "vampire.h"
#include "werewolf.h"
#include "troll.h"
#include "phoenix.h"
#include "dragon.h"
#include "merchant.h"

#include "item.h"
#include "potion.h"


#include "floor.h"
#include "cell.h"

struct Factory {
    Enemy * genEnemy();
    Potion * genPotion();
    Treasure * genTreasure();
    Floor * genFloor();
};


#endif

