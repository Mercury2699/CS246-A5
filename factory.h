#ifndef FACTORY_H
#define FACTORY_H
#include <cstdlib>
#include <ctime>
#include <memory>

#include "item.h"
#include "potion.h"
#include "player.h"
#include "enemy.h"
#include "treasure.h"
#include "floor.h"
#include "cell.h"

struct Factory {
    std::shared_ptr<Player> spawnPlayer(std::string);
    std::shared_ptr<Enemy> genEnemy();
    std::shared_ptr<Potion> genPotion();
    std::shared_ptr<Treasure> genTreasure();
    void genFloor(std::vector<std::shared_ptr<Floor>>&, int);
    std::shared_ptr<Stair> genStair(std::vector<std::shared_ptr<Floor>> &);
};


#endif

