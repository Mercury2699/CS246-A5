#ifndef CHARACTER_H
#define CHARACTER_H

#include "stuff.h"


class Character : public Stuff {

	int HP;
	int Atk;
	int Def;

	public:
	Character(int HP, int Atk, int Def) : HP{HP}, Atk{Atk}, Def{Def}{}
	int getHP() override { return HP; }
	int getAtk() override { return Atk; }
	int getDef() override { return Def; }
	bool isDead() override { return (HP <= 0); }

	void setHP(int hp) override { HP = hp; }
	void setAtk(int atk) override { Atk = atk; }
	void setDef(int def) override { Def = def; }

};

#endif



