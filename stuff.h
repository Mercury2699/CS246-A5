#ifndef STUFF_H
#define STUFF_H

#include "textDisplay.h"

// class Player;
// class Character;
class Cell;

enum Type {Plyr, Enmy, Trsr, Ptn, Itm, Str};

class Stuff {
    protected:
    Type type;

    public:
    virtual char getChar() const = 0;
    Type getType() {return type;}
    // for Itm and Ptn
    virtual void effect(std::shared_ptr<Player>) {}
    virtual std::string getName() const {return "Stuff";}
    // for Plyr and Enmy
    virtual int getHP() const {return 0;};
    virtual int getAtk() const {return 0;};
    virtual int getDef() const {return 0;};
    virtual void beAttacked(std::shared_ptr<Stuff>) = 0;
    virtual bool isDead() const {return false;}
    // for Enmy
    virtual bool checkCompass() const {return false;}
    virtual bool getMoved() const {return true;}
    virtual void toggleMoved() {} 
    // for Str
    virtual void enableDisplay() {}
    virtual ~Stuff() = default;
    // for Treasure{6} and BarrierSuit
    virtual bool isDragonHoard() {return false;}
    virtual void setCollect() {}
    virtual std::shared_ptr<Stuff> getDragon() {return nullptr;}
    virtual void setDragon(std::shared_ptr<Stuff> d) {}
};

class Stair final : public Stuff {
    // Type type; inherited from Stuff
    bool canDisplay = false;

    public:
    Stair() {this->type = Type::Str;}
    char getChar() const override {
        // if (canDisplay) 
            return '/';
        // else
        //     return '.';
    } // inherited from Stuff
    Type getType() {return type;} // inherited from Stuff
    void beAttacked(std::shared_ptr<Stuff>) override {}
    bool checkDisplay() const {return canDisplay;}
    void enableDisplay() override {canDisplay = true;}
};



#endif


