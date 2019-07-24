#include "item.h"

void BarrierSuit::effect(std::shared_ptr<Player> pc) {
    pc->setSuit(true);
}

char BarrierSuit::getChar() { 
    return 'B'; 
}

void Compass::effect(std::shared_ptr<Player> pc) {
    pc->setCompass(true);
}

char Compass::getChar() { 
    return 'C'; 
}




