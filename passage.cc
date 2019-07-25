#include "passage.h"

Passage::Passage(int x, int y):
    Cell{x, y}{}

char Passage::getChar() const {
    if(isOccupied){
        return occupant->getChar();
    }
    return '#';
}

bool Passage::checkOccupancy(bool forEnemy) const{
    return isOccupied;
}

