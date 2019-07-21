#include "emptyCell.h"

EmptyCell::EmptyCell(TextDisplay * td, int x, int y) 
    : Cell{td, x, y} {}

char EmptyCell::getState() {
    return ' ';
}
















