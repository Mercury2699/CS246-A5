#include "game.h"
#include <string>
#include <fstream>

// Valid commands during game
const std::string N = "no", S = "so", E = "ea", W = "we", NE = "ne", NW = "nw", SE = "se", SW = "sw";
const std::string UseN = "u<no>", UseS = "u<so>", UseE = "u<ea>", UseW = "u<we>";
const std::string UseNE = "u<ne>", UseNW = "u<nw>", UseSE = "u<se>", UseSW = "u<sw>";
const std::string AtkN = "a<no>", AtkS = "a<so>", AtkE = "a<ea>", AtkW = "a<we>";
const std::string AtkNE = "a<ne>", AtkNW = "a<nw>", AtkSE = "a<se>", AtkSW = "a<sw>";

Game::Game(std::string file){
    for (int count = 0; count < 5; count++){
        allFloors.emplace_back(std::make_shared<Floor>(file, pc));
    }
}

Game::Game(bool isSpecified, std::string file) 
    : specifiedLayout{isSpecified} {
    std::ifstream f{file};
    for (int count = 0; count < 5; count++){
        allFloors.emplace_back(std::make_shared<Floor>(f));
    }
}

void Game::startGame(std::string race){
    pc = f->spawnPlayer(race);
}

void Game::takeCommand(std::string action){
    
}

void Game::resetGame(){

}

