#include "item.h"

void BarrierSuit::effect(std::shared_ptr<Player> pc) {
    pc->setSuit(true);
}

char BarrierSuit::getChar() const { 
    return 'B'; 
}

std::string BarrierSuit::getName() const{
    return "Barriersuit";
} 

void Compass::effect(std::shared_ptr<Player> pc) {
    pc->setCompass(true);
}

char Compass::getChar() const { 
    return 'C'; 
}

std::string Compass::getName() const{
    return "Compass";
} 

