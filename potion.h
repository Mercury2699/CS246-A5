#ifndef POTION_H
#define POTION_H

#include <memory>
#include "item.h"

class Potion : public Item, public std::enable_shared_from_this<Potion> {
	public:
	Potion() {this->type = Type::Ptn;}
	char getChar() const override {return 'P';} // inherited from Stuff
	// virtual void effect(std::shared_ptr<Player>) {} inherited from Stuff
};

class BoostDef final : public Potion {
	public:
	void effect(std::shared_ptr<Player> pc) override;
};

class BoostAtk final : public Potion {
	public:
	void effect(std::shared_ptr<Player> pc) override;
};

class RestorHP final : public Potion {
	public:
	void effect(std::shared_ptr<Player> pc) override;
};

class PoisonHP final : public Potion {
	public:
	void effect(std::shared_ptr<Player> pc) override;
};

class WoundAtk final : public Potion {
	public:
	void effect(std::shared_ptr<Player> pc) override;
};

class WoundDef final : public Potion {
	public:
	void effect(std::shared_ptr<Player> pc) override;
};


#endif



