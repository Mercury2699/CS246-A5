#include "character.h"

Character::Character(int HP, int Atk, int Def):
	HP{HP}, Atk{Atk}, Def{Def}{}

int Character::getHP() { return HP; }

int Character::getAtk() { return Atk; }

int Character::getDef() { return Def; }

void Character::setHP(int hp) { HP = hp; }

void Character::setAtk(int atk) { Atk = atk; }

void Character::setDef(int def) { Def = def; }

bool Character::isDead() { return (HP == 0); }



