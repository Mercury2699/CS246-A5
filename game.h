#ifndef GAME_H
#define GAME_H

#include <vector>
#include <memory>
#include "factory.h"
#include "textDisplay.h"


class Game{
    std::shared_ptr<Player> pc;
    std::shared_ptr<TextDisplay> td;
    std::shared_ptr<Factory> f;
    std::vector<std::shared_ptr<Floor>> allFloors;
    int levelCount = 0;
    bool specifiedLayout = false;
    void nextFloor();

    public:
    Game(std::string file = "map.txt");
    Game(bool isSpecified, std::string file = "layout.txt");
    void startGame(std::string race);
    void takeCommand(std::string);
    void resetGame();
    
};








#endif


