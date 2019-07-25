#ifndef PHOENIX_H
#define PHOENIX_H

#include "enemy.h"
class Phoenix : public Enemy {
    // protected:
	// int HP; inherited from Character
	// int Atk; inherited from Character
	// int Def; inherited from Character
	// Type type; inherited from Stuff
	// bool alreadyMoved = false; inherited from Enemy
	// bool hasCompass = false; inherited from Enemy
	// bool hostile = false; inherited from Enemy

    public:
    Phoenix(): Enemy{50, 35, 20}{}
    char getChar() const override; // inherited from Stuff
    // int getHP() { return HP; } inherited from Character
	// int getAtk() { return Atk; } inherited from Character
	// int getDef() { return Def; } inherited from Character
	// bool isDead() { return (HP <= 0); } inherited from Character
	// void setHP(int hp) { HP = hp; } inherited from Character
	// void setAtk(int atk) { Atk = atk; } inherited from Character
	// void setDef(int def) { Def = def; } inherited from Character
	// void becomeHostile(); inherited from Enemy
	// void beAttacked(std::shared_ptr<Character> c) override; inherited from Enemy
	// void assignCompass(); inherited from Enemy
	// bool checkCompass() const; inherited from Enemy
	// bool getMoved() const; inherited from Enemy
	// virtual void toggleMoved(); inherited from Enemy
};
#endif
