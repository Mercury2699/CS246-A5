#ifndef FACTORY_H
#define FACTORY_H
#include <vector>
#include <ctime>
// PC
#include "human.h"
#include "dwarf.h"
#include "elves.h"
#include "orc.h"
// NPC
#include "vampire.h"
#include "treasure.h"
#include "werewolf.h"
#include "phoenix.h"
#include "goblin.h"
#include "merchant.h"
#include "dragon.h"
// Potions
#include "restorHP.h"
#include "boostAtk.h"
#include "boostDef.h"
#include "poisonHP.h"
#include "woundAtk.h"
#include "woundDef.h"
// Items
#include "compass.h"
#include "barrierSuit.h"




struct Factory {
    Player * createPlayer(char race);
    Enemy * genEnemy();
    Potion * genPotion();
    Treasure * genTreasure();
    Dragon * genDragon(Item *);
};

#endif




