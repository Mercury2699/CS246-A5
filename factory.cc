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

void Factory::spawnPlayer() {
    srand( time(nullptr) );
    int randNum = rand() % floorTiles.size();
    pc->setCurrPos( floorTiles[randNum] );
}


Enemy * Factory::genEnemy() {
    srand( time(nullptr) );
    int NPCRand = rand() % 18;
    
    if ( NPCRand <= 3 ) {
        return new Werewolf{nullptr};
    } else if ( NPCRand <= 6 ) {
        return new Vampire{nullptr};
    } else if ( NPCRand <= 11) {
        return new Goblin{nullptr};
    } else if ( NPCRand <= 13) {
        return new Troll{nullptr};
    } else if ( NPCRand <= 15) {
        return new Phoenix{nullptr};
    } else {
        return new Merchant{};
    }
}

Potion * Factory::genPotion() {
    srand(time(0));
    int RandNum = rand() % 6;

    if ( RandNum == 0 ) {
        return new RestorHP{};
    } else if ( RandNum == 1 ) {
        return new BoostAtk{};
    } else if ( RandNum == 2 ) {
        return new BoostDef{};
    } else if ( RandNum == 3 ) {
        return new PoisonHP{};
    } else if ( RandNum == 4 ) {
        return new WoundAtk{};
    } else { // if ( RandNum == 5 )
        return new WoundDef{};
    }
}

Treasure * Factory::genTreasure(){
    srand(time(0));
    int RandNum = rand() % 4;

    if (RandNum == 0){
        return new Treasure{1};
    } else if (RandNum == 1) {
        return new Treasure{2};
    } else if (RandNum == 2) {
        return new Treasure{4};
    } else { // RandNum == 3s
        return new Treasure{6};
    }
}

void Factory::genFloor(Floor *){

}


