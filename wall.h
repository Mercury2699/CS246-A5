#ifndef WALL_H
#define WALL_H
#include "cell.h"

 class Wall final : private Cell{
    bool isHorizontal;
    public:
    Wall(int x, int y, bool isHor) : isHorizontal{isHor} {
        this->x = x;
        this->y = y;
    }
    char getChar() override {
        if (isHorizontal) return '-';
        return '|';
    }
};

#endif



