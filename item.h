#ifndef ITEM_H
#define ITEM_H

#include <memory>
#include "stuff.h"
#include "player.h"

class Item : public Stuff {
    // protected:
    // Type type; inherited from Stuff
    public:
    Item(){ this->type = Type::Itm;}
    // Type getType(); inherited from Stuff
    // virtual char getChar() = 0; inherited from Stuff
    virtual void effect(std::shared_ptr<Player>) = 0;
};

class BarrierSuit final : public Item {
    // protected:
    // Type type; inherited from Stuff
    public:
    char getChar() const override; // inherited from Stuff
    void effect(std::shared_ptr<Player>) override; // inherited from Item
};

struct Compass final : public Item {
    // protected:
    // Type type; inherited from Stuff
    // public:
    char getChar() const override; // inherited from Stuff
    void effect(std::shared_ptr<Player>) override; // inherited from Item
};

class Stair final : public Item {
    // Type type; inherited from Stuff
    bool canDisplay = false;

    public:
    char getChar() const override; // inherited from Stuff
    void effect(std::shared_ptr<Player>) override; // inherited from Item
};


#endif
