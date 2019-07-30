#include "game.h"
#include <string>
#include <fstream>
#include <sstream>

// Valid commands during game
const char N = '8', S = '2', E = '6', W = '4' , NE = '9', NW = '7', SE = '3', SW = '1';
const char Use = 'u', Atk = 'a', restart = 'r', quit = 'q';

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

Game::Game(char race, bool isSpecified, std::string file) {
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
    if (action == N || action == (char)KEY_UP) move = allFloors[levelCount]->playerMove("N");
    else if (action == S || action == (char)KEY_DOWN) move = allFloors[levelCount]->playerMove("S");
    else if (action == E || action == (char)KEY_RIGHT) move = allFloors[levelCount]->playerMove("E");
    else if (action == W || action == (char)KEY_LEFT) move = allFloors[levelCount]->playerMove("W");
    else if (action == NE) move = allFloors[levelCount]->playerMove("NE");
    else if (action == NW) move = allFloors[levelCount]->playerMove("NW");
    else if (action == SE) move = allFloors[levelCount]->playerMove("SE");
    else if (action == SW) move = allFloors[levelCount]->playerMove("SW");
    else if (action == Use){
        action = getch();
        if (action == N || action == (char)KEY_UP) allFloors[levelCount]->playerUse("N");
        else if (action == S || action == (char)KEY_DOWN) allFloors[levelCount]->playerUse("S");
        else if (action == E || action == (char)KEY_RIGHT) allFloors[levelCount]->playerUse("E");
        else if (action == W || action == (char)KEY_LEFT) allFloors[levelCount]->playerUse("W");
        else if (action == NE) allFloors[levelCount]->playerUse("NE");
        else if (action == NW) allFloors[levelCount]->playerUse("NW");
        else if (action == SE) allFloors[levelCount]->playerUse("SE");
        else if (action == SW) allFloors[levelCount]->playerUse("SW");
        else {
            td->addAction("Invalid Operation!");
            valid = false;
        }
    } else if (action == Atk) {
        action = getch();
        if (action == N || action == (char)KEY_UP) allFloors[levelCount]->playerAtk("N");
        else if (action == S || action == (char)KEY_DOWN) allFloors[levelCount]->playerAtk("S");
        else if (action == E || action == (char)KEY_RIGHT) allFloors[levelCount]->playerAtk("E");
        else if (action == W || action == (char)KEY_LEFT) allFloors[levelCount]->playerAtk("W");
        else if (action == NE) allFloors[levelCount]->playerAtk("NE");
        else if (action == NW) allFloors[levelCount]->playerAtk("NW");
        else if (action == SE) allFloors[levelCount]->playerAtk("SE");
        else if (action == SW) allFloors[levelCount]->playerAtk("SW");
        else {
            td->addAction("Invalid Operation!");
            valid = false;
        }
    } else if (action == restart) {
        return 5;
    } else if (action == quit){
        return 4;
    } else {
        td->addAction("Invalid Operation!");
        valid = false;
    }

    if (move == 1) return nextFloor();
    if (move == 3) valid = false;
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
    pc->setKilledMerch(false);
    allFloors[levelCount]->notifyObserver();
    td->addAction("PC has entered Floor " + std::to_string(levelCount + 1) + ". ");
    pc->removePotion();
    std::cout << *td;
    return 0;
}

void Game::gameOver(){
    clear();
    mvprintw(0, 0, "%s", "GAME OVER!!! ");
    mvprintw(1, 0, "%s", "YOU DIED.");
    double score = pc->getTreasure();
    if (pc->getRace() == "Human"){
        score *= 1.5;
    }
    std::stringstream s;
    s << "Your score is: " << score;
    mvprintw(2, 0, "%s", s.str().c_str());
}

void Game::gameWon(){
    clear();
    mvprintw(0, 0, "%s", "GAME WON!!!");
    mvprintw(1, 0, "%s", "YOU HAVE ESCAPED FROM THE DUNGEON!!!");
    double score = pc->getTreasure();
    if (pc->getRace() == "Human"){
        score *= 1.5;
    }
    std::stringstream s;
    s << "Your score is: " << score;
    mvprintw(2, 0, "%s", s.str().c_str());
}




