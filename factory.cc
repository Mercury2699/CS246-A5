#include "factory.h"

//Players
#include "human.h"
#include "orc.h"
#include "elves.h"
#include "dwarf.h"

// Enemies
#include "vampire.h"
#include "werewolf.h"
#include "troll.h"
#include "phoenix.h"
#include "dragon.h"
#include "merchant.h"
#include "goblin.h"

using std::make_shared;

std::shared_ptr<Player> spawnPlayer(std::string race) {
    
}

// void Factory::spawnPlayer(std::vector<std::shared_ptr<Floor>> f) {
//     srand( time(nullptr) );
//     int randChamber = rand() % f[0]->getChambers().size();
//     int randPos = rand() % f[0]->getChambers()[randChamber].size();
//     Cell *playerPos = f[0]->getChambers()[randPos];
//     f[0]->getPlayer()->setCurrPos( playerPos );
//     theGrid[playerPos.getX]
// }


std::shared_ptr<Enemy> Factory::genEnemy() {
    srand( time(nullptr) );
    int NPCRand = rand() % 18;
    
    if ( NPCRand <= 3 ) { // if (NPCRand == 0, 1, 2, 3)
        return make_shared<Enemy>(Werewolf{nullptr});
    } else if ( NPCRand <= 6 ) { // if (NPCRand == 4, 5, 6)
        return make_shared<Enemy>(Vampire{nullptr});
    } else if ( NPCRand <= 11) { // if (NPCRand == 7, 8, 9, 10, 11)
        return make_shared<Enemy>(Goblin{nullptr});
    } else if ( NPCRand <= 13) { // if (NPCRand == 12,13) 
        return make_shared<Enemy>(Troll{nullptr});
    } else if ( NPCRand <= 15) { // if (NPCRand == 14,15)
        return make_shared<Enemy>(Phoenix{nullptr});
    } else { // if (NPCRand == 16,17)
        return make_shared<Enemy>(Merchant{});
    }
}

std::shared_ptr<Potion> Factory::genPotion() {
    srand(time(0));
    int RandNum = rand() % 6;

    if ( RandNum == 0 ) {
        return make_shared<Potion>(RestorHP{});
    } else if ( RandNum == 1 ) {
        return make_shared<Potion>(BoostAtk{});
    } else if ( RandNum == 2 ) {
        return make_shared<Potion>(BoostDef{});
    } else if ( RandNum == 3 ) {
        return make_shared<Potion>(PoisonHP{});
    } else if ( RandNum == 4 ) {
        return make_shared<Potion>(WoundAtk{});
    } else { // if ( RandNum == 5 )
        return make_shared<Potion>(WoundDef{});
    }
}

std::shared_ptr<Treasure> Factory::genTreasure(){
    srand( time(0) );
    int RandNum = rand() % 4;

    if ( RandNum == 0 ){
        return make_shared<Treasure>(Treasure{1});
    } else if ( RandNum == 1 ) {
        return make_shared<Treasure>(Treasure{2});
    } else if ( RandNum == 2 ) {
        return make_shared<Treasure>(Treasure{4});
    } else { // if ( RandNum == 3 )
        return make_shared<Treasure>(Treasure{6});
    }
}

void Factory::genFloor(std::vector<std::shared_ptr<Floor>> f) {

    // set random seed
    srand( time(nullptr) );

    // player spawned
    int i = rand() % f[0]->getChambers().size();
    int x = rand() % f[0]->getChambers()[i].size();
    int y = rand() % f[0]->getChambers()[i][x].size();
    Cell *playerPos = f[0]->getChambers()[i][x][y];
    f[0]->getPlayer()->setCell( playerPos );
    Grid[ playerPos->getX() ][ playerPos->getY() ]->setOccupant() = f[0]->getPlayer();

    // stair spawned
    int diffChamber = rand() % f[0]->getChambers().size();
    while (diffChamber == randChamber) {
        diffChamber = rand() % f[0]->getChambers().size();
    }
    int randStair = rand();

}


