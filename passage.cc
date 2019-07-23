#include "passage.h"

Passage::Passage(int x, int y) {
    this->x = x;
    this->y = y;
}

bool Passage::checkOccupancy(){
    return (isOccupied && occupant);
}

void Passage::setObserver(TextDisplay * td){
    this->td = td;
}

void Passage::notifyObserver(){
    td->notify(x,y,getChar());
}

Stuff * Passage::getOccupant(){
    return occupant;
}

char Passage::getChar(){
    if(checkOccupancy()){
        return getOccupant()->getChar();
    }
    return '#';
}

