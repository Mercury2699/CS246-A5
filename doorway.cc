#include "doorway.h"

Doorway::Doorway(int x, int y) {
    this->x = x;
    this->y = y;
}

bool Doorway::checkOccupancy(){
    return (isOccupied && occupant);
}

void Doorway::setObserver(TextDisplay * td){
    this->td = td;
}

void Doorway::notifyObserver(){
    td->notify(x,y,getChar());
}

Stuff * Doorway::getOccupant(){
    return occupant;
}

void Doorway::attachStuff(Stuff * s){
    isOccupied = true;
    occupant = s;
    notifyObserver();
}

Stuff* Doorway::detachStuff(){
    Stuff * temp = occupant;
    isOccupied = false;
    occupant = nullptr;
    notifyObserver();
    return temp;
}

char Doorway::getChar() {
    if(checkOccupancy())
        return getOccupant()->getChar();
    return '.';
}

