#include "game.h"
#include <string>
#include <fstream>

// Valid commands during game
// const std::string N = "no", S = "so", E = "ea", W = "we", NE = "ne", NW = "nw", SE = "se", SW = "sw";
const char N = '8', S = '2', E = '6', W = '4' , NE = '9', NW = '5', SE = '3', SW = '1';
const char Use = 'u';
const char Atk = 'a';

Game::Game(char race, std::string file){
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

Game::Game(char race, bool isSpecified, std::string file) 
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


int Game::takeCommand(){
    if (pc->isDead()) {
        gameOver();
        return 1;
    }
    bool valid = true;
    int move = 0;
    char action = getch();
    if (action == N || action == KEY_UP) move = allFloors[levelCount]->playerMove("N");
    else if (action == S || action == KEY_DOWN) move = allFloors[levelCount]->playerMove("S");
    else if (action == E || action == KEY_RIGHT) move = allFloors[levelCount]->playerMove("E");
    else if (action == W || action == KEY_LEFT) move = allFloors[levelCount]->playerMove("W");
    else if (action == NE) move = allFloors[levelCount]->playerMove("NE");
    else if (action == NW) move = allFloors[levelCount]->playerMove("NW");
    else if (action == SE) move = allFloors[levelCount]->playerMove("SE");
    else if (action == SW) move = allFloors[levelCount]->playerMove("SW");
    else if (action == Use){
        action = getch();
        if (action == N || action == KEY_UP) allFloors[levelCount]->playerUse("N");
        else if (action == S || action == KEY_DOWN) allFloors[levelCount]->playerUse("S");
        else if (action == E || action == KEY_RIGHT) allFloors[levelCount]->playerUse("E");
        else if (action == W || action == KEY_LEFT) allFloors[levelCount]->playerUse("W");
        else if (action == NE) allFloors[levelCount]->playerUse("NE");
        else if (action == NW) allFloors[levelCount]->playerUse("NW");
        else if (action == SE) allFloors[levelCount]->playerUse("SE");
        else if (action == SW) allFloors[levelCount]->playerUse("SW");
    } else if (action == Atk) {
        action = getch();
        if (action == N || action == KEY_UP) allFloors[levelCount]->playerAtk("N");
        else if (action == S || action == KEY_DOWN) allFloors[levelCount]->playerAtk("S");
        else if (action == E || action == KEY_RIGHT) allFloors[levelCount]->playerAtk("E");
        else if (action == W || action == KEY_LEFT) allFloors[levelCount]->playerAtk("W");
        else if (action == NE) allFloors[levelCount]->playerAtk("NE");
        else if (action == NW) allFloors[levelCount]->playerAtk("NW");
        else if (action == SE) allFloors[levelCount]->playerAtk("SE");
        else if (action == SW) allFloors[levelCount]->playerAtk("SW");
    } else {
        td->addAction("Invalid Operation!");
        valid = false;
    }

    if (move == 1) return nextFloor();

    if (valid) {
        allFloors[levelCount]->moveEnemies();
        allFloors[levelCount]->checkEvents();  
    }

    std::cout << *td;
    td->clearAction();
    
    return 0;
}

void Game::resetGame(){
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
    double score = pc->getTreasure();
    if (pc->getRace() == "Human"){
        score *= 1.5;
    }
    std::cout << "Your score is: " << score << std::endl;
}

void Game::gameWon(){
    std::cout << "GAME WON!!! " << std::endl;
    std::cout << "YOU HAVE ESCAPED FROM THE DUNGEON!!!" << std::endl;
    double score = pc->getTreasure();
    if (pc->getRace() == "Human"){
        score *= 1.5;
    }
    std::cout << "Your score is: " << score << std::endl;
}




