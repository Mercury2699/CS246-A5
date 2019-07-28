#include "dragon.h"

Dragon::Dragon(): Enemy{150, 20, 20} {
	alreadyMoved = true;
} 

char Dragon::getChar() const {
    return 'D';
}

void Dragon::toggleMoved() {
    alreadyMoved = true;
}






