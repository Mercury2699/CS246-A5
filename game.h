#ifndef GAME_H
#define GAME_H

#include <vector>
#include <string>
#include <memory>
#include "floor.h"
#include "player.h"

class Game{
    std::shared_ptr<Player> pc;
    std::vector<std::shared_ptr<Floor>> allFloors;
    
};








#endif


