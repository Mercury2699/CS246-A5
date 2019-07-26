#ifndef POTION_H
#define POTION_H

#include <memory>
#include "item.h"

class Potion : public Item {
	public:
	Potion() {this->type = Type::Ptn;}
	char getChar() const override {return 'P';} // inherited from Stuff
	// virtual void effect(std::shared_ptr<Player>) {} inherited from Stuff
};

class BoostDef final : public Potion {
	public:
	void effect(std::shared_ptr<Player> pc) override;
	std::string getName() const override{
		return "Boost Defense";
	}
};

class BoostAtk final : public Potion {
	public:
	void effect(std::shared_ptr<Player> pc) override;
	std::string getName() const override{
		return "Boost Attack";
	}
};

class RestorHP final : public Potion {
	public:
	void effect(std::shared_ptr<Player> pc) override;
	std::string getName() const override{
		return "Restore HP";
	}
};

class PoisonHP final : public Potion {
	public:
	void effect(std::shared_ptr<Player> pc) override;
	std::string getName() const override{
		return "Poison HP";
	}
};

class WoundAtk final : public Potion {
	public:
	void effect(std::shared_ptr<Player> pc) override;
	std::string getName() const override{
		return "Wound Attack";
	}
};

class WoundDef final : public Potion {
	public:
	void effect(std::shared_ptr<Player> pc) override;
	std::string getName() const override{
		return "Wound Defense";
	}
};


#endif



