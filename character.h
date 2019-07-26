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

    // for Itm and Ptn
    // virtual void effect(std::shared_ptr<Player>) {}
    // virtual std::string getName() const {return "Stuff";}
    // for Plyr and Enmy
	int getHP() const override { return HP; } // inherited from Stuff
	int getAtk() const override { return Atk; } // inherited from Stuff
	int getDef() const override { return Def; } // inherited from Stuff
	bool isDead() const override { return (HP <= 0); } // inherited from Stuff
    // virtual void beAttacked(std::shared_ptr<Stuff>) = 0;
    // for Enmy
    // virtual bool checkCompass() const {return false;}
    // virtual bool getMoved() const {return true;}
    // virtual void toggleMoved() {} 
    // for Str
    // virtual void enableDisplay() {}
    // virtual ~Stuff() = default;
    // for Treasure{6}
    // virtual bool isDragonHoard() {return false;}
    // virtual void setCollect() {}
	void setHP(int hp) { HP = hp; }
	void setAtk(int atk) { Atk = atk; }
	void setDef(int def) { Def = def; }

};

#endif



