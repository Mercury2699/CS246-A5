#include "cell.h"

Cell::Cell(TextDisplay * td, int x, int y) : x{x}, y{y}, td{td} {}

int Cell::getX() {return x;}

int Cell::getY() {return y;}

bool Cell::checkOccupancy() {return isOccupied;}

void Cell::notifyObserver() {td->notify(x,y,getState());}

Stuff * Cell::getOccupant() {
    return occupant;
}


