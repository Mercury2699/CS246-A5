#ifndef EMPTYCELL_H
#define EMPTYCELL_H
#include "cell.h"

struct EmptyCell : public Cell {
    char getState() override {
        return ' ';
    }
};
#endif

