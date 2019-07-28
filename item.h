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
    // virtual void effect(std::shared_ptr<Player>) {} inherited from Stuff
    virtual void beAttacked(std::shared_ptr<Stuff>) {}
    virtual ~Item() = default;
};

class BarrierSuit final : public Item {
    // protected:
    // Type type; inherited from Stuff
    bool canCollect = false;
    std::shared_ptr<Stuff> dragon;
    public:
    // Type getType(); inherited from Stuff
    std::string getName() const override; // inherited from Stuff
    char getChar() const override; // inherited from Stuff
    void effect(std::shared_ptr<Player>) override; // inherited from Item
    bool isDragonHoard() override;
    virtual void setCollect() override { canCollect = true ;}
    std::shared_ptr<Stuff> getDragon() override;
    void setDragon(std::shared_ptr<Stuff> d) override {dragon = d; }
};

struct Compass final : public Item {
    // protected:
    // Type type; inherited from Stuff
    // public:
    // Type getType(); inherited from Stuff
    char getChar() const override; // inherited from Stuff
    std::string getName() const override; // inherited from Stuff
    void effect(std::shared_ptr<Player>) override; // inherited from Item
};

#endif



