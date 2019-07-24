#ifndef ITEM_H
#define ITEM_H

#include <memory>
#include "stuff.h"
#include "player.h"

class Stuff;

class Item : public Stuff {
    // Type type; inherited from Stuff
    public:
    // Type getType(); inherited from Stuff
    Item(){ this->type = Type::Itm;}
    // virtual char getChar() = 0;
    virtual void effect(std::shared_ptr<Player>) = 0;
};

class BarrierSuit : public Item {
    void effect(std::shared_ptr<Player>) override;
    char getChar() const override;
};

struct Compass : public Item {
    void effect(std::shared_ptr<Player>) override;
    char getChar() const override;
};


#endif
