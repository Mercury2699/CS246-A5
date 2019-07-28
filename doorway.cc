#include "doorway.h"

Doorway::Doorway(int x, int y):
    Cell{x, y}{}

char Doorway::getChar() const {
    if(isOccupied)
        return occupant->getChar();
    return '+';
}

bool Doorway::checkOccupancy() const{
    return isOccupied;
}





