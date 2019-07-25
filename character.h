#ifndef CHARACTER_H
#define CHARACTER_H

#include <memory>
#include "stuff.h"

class Character : public Stuff {
	protected:
	// Type type; inherited from Stuff
	int HP;
	int Atk;
	int Def;

	public:	
	// Type getType(); inherited from Stuff
	// virtual char getChar() const = 0; inherited from Stuff
	Character(int HP, int Atk, int Def) : HP{HP}, Atk{Atk}, Def{Def}{}
	int getHP() const override { return HP; } // inherited from Stuff
	int getAtk() const override { return Atk; } // inherited from Stuff
	int getDef() const override { return Def; } // inherited from Stuff
	bool isDead() const override { return (HP <= 0); } // inherited from Stuff
    
	void setHP(int hp) { HP = hp; }
	void setAtk(int atk) { Atk = atk; }
	void setDef(int def) { Def = def; }

};

#endif



