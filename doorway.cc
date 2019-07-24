#include "doorway.h"

Doorway::Doorway(int x, int y):
    Cell{x, y}{}

char Doorway::getChar() {
    if(checkOccupancy())
        return getOccupant()->getChar();
    return '.';
}



