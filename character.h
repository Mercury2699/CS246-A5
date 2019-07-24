#ifndef CHARACTER_H
#define CHARACTER_H

#include "stuff.h"

class Character : public Stuff {

	int HP;
	int Atk;
	int Def;

	public:
	Character(int HP, int Atk, int Def) : HP{HP}, Atk{Atk}, Def{Def}{}
	int getHP() { return HP; }
	int getAtk() { return Atk; }
	int getDef() { return Def; }
	bool isDead() { return (HP <= 0); }
	virtual void attack(Character *) = 0;
    virtual void beAttacked(Character *) = 0;

	void setHP(int hp) { HP = hp; }
	void setAtk(int atk) { Atk = atk; }
	void setDef(int def) { Def = def; }

};

#endif



