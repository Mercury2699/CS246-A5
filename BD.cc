#include "BD.h"

BD::effect(Human &h) {
	return new Human{h.getHP(), h.getAtk(), h.getDef() + 5};
}

BD::effect(Dwarf &d) {
	return new Dwarf{d.getHP(), d.getAtk(), d.getDef() + 5};
}

BD::effect(Orc &o) {
	return new Orc{o.getHP(), o.getAtk(), o.getDef() + 5};
}

BD::effect(Elves &e) {
	return new Elves{e.getHP(), e.getAtk(), e.getDef() + 5};
}