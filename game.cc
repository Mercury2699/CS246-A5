#include "game.h"
#include <string>
#include <fstream>

// Valid commands during game
const std::string N = "no", S = "so", E = "ea", W = "we", NE = "ne", NW = "nw", SE = "se", SW = "sw";
const std::string UseN = "uno", UseS = "uso", UseE = "uea", UseW = "uwe";
const std::string UseNE = "une", UseNW = "unw", UseSE = "use", UseSW = "usw";
const std::string AtkN = "ano", AtkS = "aso", AtkE = "aea", AtkW = "awe";
const std::string AtkNE = "ane", AtkNW = "anw", AtkSE = "ase", AtkSW = "asw";
const std::string restart = "r", quit = "q";

Game::Game(std::string race, std::string file){
    td = std::make_shared<TextDisplay>();
    pc = f.spawnPlayer(race);
    td->setPC(pc);
    td->addAction("Game Started as " + pc->getRace() + " ! ");
    for (int count = 0; count < 5; count++){
        allFloors.emplace_back(std::make_shared<Floor>(file));
        allFloors[count]->setPC(pc);
        allFloors[count]->setTD(td);
    }
    f.genFloor(allFloors);
    allFloors[levelCount]->notifyObserver();
    std::cout << *td;
    td->clearAction();
}

Game::Game(std::string race, bool isSpecified, std::string file) 
    /*: specifiedLayout{isSpecified} */ {
    td = std::make_shared<TextDisplay>();
    pc = f.spawnPlayer(race);
    td->setPC(pc);
    td->addAction("Game Started as " + pc->getRace() + " ! ");
    std::ifstream fs{file};
    for (int count = 0; count < 5; count++){
        allFloors.emplace_back(std::make_shared<Floor>(pc,fs));
        allFloors[count]->setPC(pc);
        allFloors[count]->setTD(td);
    }
    allFloors[levelCount]->notifyObserver();
    
    std::cout << *td;
    td->clearAction();
}

// void Game::startGame(std::string race){
// }

int Game::takeCommand(std::string action){
    // if (pc->isDead()) {
    //     gameOver();
    //     return 1;
    // }
    bool valid = true;
    int move = 0;
    if (action == N) move = allFloors[levelCount]->playerMove("N");
    else if (action == S) move = allFloors[levelCount]->playerMove("S");
    else if (action == E) move = allFloors[levelCount]->playerMove("E");
    else if (action == W) move = allFloors[levelCount]->playerMove("W");
    else if (action == NE) move = allFloors[levelCount]->playerMove("NE");
    else if (action == NW) move = allFloors[levelCount]->playerMove("NW");
    else if (action == SE) move = allFloors[levelCount]->playerMove("SE");
    else if (action == SW) move = allFloors[levelCount]->playerMove("SW");
    else if (action == UseN) allFloors[levelCount]->playerUse("N");
    else if (action == UseS) allFloors[levelCount]->playerUse("S");
    else if (action == UseE) allFloors[levelCount]->playerUse("E");
    else if (action == UseW) allFloors[levelCount]->playerUse("W");
    else if (action == UseNE) allFloors[levelCount]->playerUse("NE");
    else if (action == UseNW) allFloors[levelCount]->playerUse("NW");
    else if (action == UseSE) allFloors[levelCount]->playerUse("SE");
    else if (action == UseSW) allFloors[levelCount]->playerUse("SW");
    else if (action == AtkN) allFloors[levelCount]->playerAtk("N");
    else if (action == AtkS) allFloors[levelCount]->playerAtk("S");
    else if (action == AtkE) allFloors[levelCount]->playerAtk("E");
    else if (action == AtkW) allFloors[levelCount]->playerAtk("W");
    else if (action == AtkNE) allFloors[levelCount]->playerAtk("NE");
    else if (action == AtkNW) allFloors[levelCount]->playerAtk("NW");
    else if (action == AtkSE) allFloors[levelCount]->playerAtk("SE");
    else if (action == AtkSW) allFloors[levelCount]->playerAtk("SW");
    else {
        td->addAction("Invalid Operation!");
        valid = false;
    }
    if (valid) {
        allFloors[levelCount]->moveEnemies();
        allFloors[levelCount]->checkEvents();
    }
    std::cout << *td;
    td->clearAction();
    if (move == 1) return nextFloor();
    return 0;
}

void Game::resetGame(){
    // std::string race;
    // std::cin >> race;
    levelCount = 0;
}

int Game::nextFloor() {
    levelCount++;
    if (levelCount >= 5){
        td->addAction("PC has won this Game!");
        gameWon();
        return 1;
    }
    allFloors[levelCount]->notifyObserver();
    td->addAction("PC has entered Floor " + std::to_string(levelCount + 1) + ". ");
    pc->removePotion();
    std::cout << *td;
    return 0;
}

void Game::gameOver(){
    std::cout << "GAME OVER!!! " << std::endl;
    std::cout << "YOU DIED." << std::endl;
    std::cout << "Your score is: " << pc->getTreasure() << std::endl;
}

void Game::gameWon(){
    std::cout << "GAME WON!!! " << std::endl;
    std::cout << "YOU HAVE EACAPED FROM THE DUNGEON!!!" << std::endl;
    std::cout << "Your score is: " << pc->getTreasure() << std::endl;
}




