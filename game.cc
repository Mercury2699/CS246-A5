#include "game.h"
#include <string>
#include <fstream>

// Valid commands during game
const std::string N = "no", S = "so", E = "ea", W = "we", NE = "ne", NW = "nw", SE = "se", SW = "sw";
const std::string UseN = "u<no>", UseS = "u<so>", UseE = "u<ea>", UseW = "u<we>";
const std::string UseNE = "u<ne>", UseNW = "u<nw>", UseSE = "u<se>", UseSW = "u<sw>";
const std::string AtkN = "a<no>", AtkS = "a<so>", AtkE = "a<ea>", AtkW = "a<we>";
const std::string AtkNE = "a<ne>", AtkNW = "a<nw>", AtkSE = "a<se>", AtkSW = "a<sw>";
const std::string restart = "r", quit = "q";

Game::Game(std::string race, std::string file){
    td = std::make_unique<TextDisplay>();
    pc = f->spawnPlayer(race);
    td->setPC(pc.get());
    for (int count = 0; count < 5; count++){
        allFloors.emplace_back(std::make_shared<Floor>(td.get(), pc, file));
        f->genFloor(allFloors);
    }
}

Game::Game(std::string race, bool isSpecified, std::string file) 
    : specifiedLayout{isSpecified} {
    td = std::make_unique<TextDisplay>();
    std::cout << &td;
    std::cout << td.get();
    pc = f->spawnPlayer(race);
    td->setPC(pc.get());
    std::ifstream fs{file};
    for (int count = 0; count < 5; count++){
        allFloors.emplace_back(std::make_shared<Floor>(td.get(), pc, fs));
    }
    f->genFloor(allFloors);
}

// void Game::startGame(std::string race){
// }

void Game::takeCommand(std::string action){
    if (action == N) allFloors[levelCount]->playerMove("N");
    else if (action == S) allFloors[levelCount]->playerMove("S");
    else if (action == E) allFloors[levelCount]->playerMove("E");
    else if (action == W) allFloors[levelCount]->playerMove("W");
    else if (action == NE) allFloors[levelCount]->playerMove("NE");
    else if (action == NW) allFloors[levelCount]->playerMove("NW");
    else if (action == SE) allFloors[levelCount]->playerMove("SE");
    else if (action == SW) allFloors[levelCount]->playerMove("SW");
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
    else if (action == restart) resetGame();
    else if (action == quit) return;
}

void Game::resetGame(){
    std::string race;
    std::cin >> race;
    levelCount = 0;
    // startGame(race);
    f->genFloor(allFloors);
}

