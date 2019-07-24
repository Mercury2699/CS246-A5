#ifndef EMPTYCELL_H
#define EMPTYCELL_H
#include "cell.h"

struct EmptyCell : public Cell {
    EmptyCell(int x, int y):
        Cell{x, y}{}
    char getChar() const override {return ' ';};
    bool checkOccupancy() override { return true; }
};

#endif

