#ifndef ELVES_H
#define ELVES_H
#include "player.h"
#include "woundAtk.h"
#include "woundDef.h"

class Elves : public Player {

	public:
	Elves(int HP = 140, int Atk = 30, int Def = 10, double treasure = 0);
	void applyPotion(WoundAtk &wa) override;
	void applyPotion(WoundDef &wd) override;
	void removePotion(WoundAtk &wa) override;
	void removePotion(WoundDef &wd) override;
};

#endif



