#ifndef WALL_H
#define WALL_H
#include "cell.h"

 class Wall final : public Cell{
    bool isHorizontal;
    public:
    Wall(int x, int y, bool isHor) : Cell{x, y}, isHorizontal{isHor} {
        setOccupancy(true);
    }
    bool checkOccupancy() override { return true; }
    char getChar() const override {
        if (isHorizontal) return '-';
        return '|';
    }
};

#endif



