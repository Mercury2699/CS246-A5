#include "human.h"

Human::Human(int HP, int Atk, int Def, double treasure):
	Player{HP, Atk, Def, treasure}{}

void Human::applyPotion(Potion *p) {
	p->effect(*this);
}