#ifndef DOORWAY_H
#define DOORWAY_H
#include "cell.h"


class Doorway final : public Cell {
    public:
    Doorway(int x, int y);
    char getChar() const override;
    bool checkOccupancy(bool forEnemy) const override;
};

#endif



