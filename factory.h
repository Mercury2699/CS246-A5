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
#include "RH.h"
#include "BA.h"
#include "BD.h"
#include "PH.h"
#include "WA.h"
#include "WD.h"
// Treasures
#include "normal.h"
#include "small.h"
#include "merchantHoard.h"
#include "dragonHoard.h"
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




