#ifndef WALL_H
#define WALL_H
#include "cell.h"

class Wall : public Cell {
    bool isHorizontal;
    public:
    Wall(int x, int y, bool isHor);
    char getState() override;
};

#endif



