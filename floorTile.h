#ifndef FLOORTILE_H
#define FLOORTILE_H
#include "cell.h"

class FloorTile : public Cell {

    char getState() override {
        if(checkOccupancy())
            return getOccupant()->getState();
        return '.';
    }
    
};
#endif
