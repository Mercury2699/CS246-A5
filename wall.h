#ifndef WALL_H
#define WALL_H
#include "cell.h"

class Wall : public Cell {
    bool isHorizontal;
    public:
    char getState() override {
        if (isHorizontal) return '-';
        return '|';
    }
};

#endif



