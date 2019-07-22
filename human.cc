#include "human.h"

Human::Human(int HP, int Atk, int Def):
	Character{HP, Atk, Def}{}

void Human::applyPotion(Potion *p) {
	p->effect(*this);
}