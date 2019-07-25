#include "item.h"

void BarrierSuit::effect(std::shared_ptr<Player> pc) {
    pc->setSuit(true);
}

char BarrierSuit::getChar() const { 
    return 'B'; 
}

void Compass::effect(std::shared_ptr<Player> pc) {
    pc->setCompass(true);
}

char Compass::getChar() const { 
    return 'C'; 
}

void Stair::effect(std::shared_ptr<Player> pc) {
}

void Stair::setDisplay() {
    canDisplay = true;
}

char Stair::getChar() const { 
    return '/'; 
}


