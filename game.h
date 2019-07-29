#ifndef GAME_H
#define GAME_H

#include <vector>
#include <memory>
#include "factory.h"
#include "textDisplay.h"


class Game{
    std::shared_ptr<Player> pc;
    std::vector<std::shared_ptr<Floor>> allFloors;
    std::shared_ptr<TextDisplay> td;
    Factory f;
    int levelCount = 0;
    int nextFloor();

    public:
    Game(char race, std::string file = "map.txt");
    Game(char race, bool isSpecified, std::string file = "layout.txt");
    int takeCommand();
    void resetGame();
    void gameOver();
    void gameWon();
};


#endif






