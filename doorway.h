#ifndef DOORWAY_H
#define DOORWAY_H
#include "cell.h"

class Doorway : public Cell {
    char getState() override {
        return '+';
    }
};

#endif
