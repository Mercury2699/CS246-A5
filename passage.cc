#include "passage.h"

Passage::Passage(int x, int y):
    Cell{x, y}{}

char Passage::getChar() const override {
    if(checkOccupancy()){
        return getOccupant()->getChar();
    }
    return '#';
}

