#ifndef GAME_H
#define GAME_H

#include <vector>
#include <memory>
#include "factory.h"
#include "textDisplay.h"


class Game{
    std::shared_ptr<Player> pc;
    std::unique_ptr<TextDisplay> td = std::make_unique<TextDisplay>();
    std::shared_ptr<Factory> f;
    std::vector<std::shared_ptr<Floor>> allFloors;
    int levelCount = 0;
    bool specifiedLayout = false;
    void nextFloor();

    public:
    Game(std::string race, std::string file = "map.txt");
    Game(std::string race, bool isSpecified, std::string file = "layout.txt");
    // void startGame();
    void takeCommand(std::string);
    void resetGame();
    
};








#endif


