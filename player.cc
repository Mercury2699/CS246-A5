#include <cmath>
#include "player.h"
#include "potion.h"
#include "treasure.h"

Player::Player(int HP, int Atk, int Def, double treasure):
	Character{HP, Atk, Def}, treasure{treasure}, maxHP{HP}, defaultAtk{Atk}, defaultDef{Def}{
		type = Type::Plyr;
	}

void Player::setTreasure(double t) {
	treasure = t;
}

double Player::getTreasure() {return treasure;}

void Player::setSuit(bool suit) {
	hasSuit = suit;
}

void Player::setCompass(bool comp) {
	hasCompass = comp;
}

// void Player::setPosn(int x, int y){
// 	this->x = x;
// 	this->y = y;
// }

// int Player::getX(){return x;}

// int Player::getY(){return y;}

bool Player::getSuit() {
	return hasSuit;
}

int Player::getDefaultAtk() {
	return defaultAtk;
}

int Player::getDefaultDef() {
	return defaultDef;
}

void Player::pickUpTreasure(std::shared_ptr<Treasure> t) {
	setTreasure(t->getValue());
}

void Player::attack(std::shared_ptr<Character> c) {
	c->beAttacked(std::make_shared<Player> (this));
	c->attack(std::make_shared<Player> (this));
}

void Player::beAttacked(std::shared_ptr<Character> c) {
	if (getSuit()) {
		setHP(getHP() - ceil(ceil(((100 / (100 + getDef())) * c->getAtk())) / 2));
	} else {
		setHP(getHP()- ceil((100 / (100 + getDef())) * c->getAtk()));
	}
}

void Player::applyPotion(std::shared_ptr<Potion> p) {
	p->effect(std::make_shared<Player> (this));
}

void Player::killedMerchant(){
	killedMerch = true;
}

bool Player::hasKilledMerch(){
	return killedMerch;
};

void Player::removePotion() {
	setAtk(getDefaultAtk());
	setDef(getDefaultDef());
}

char Player::getChar() {
	return '@';
}

PCRace Player::getRace(){
	return race;
}

int Player::getMaxHP() const {
	return maxHP;
}




