CXX = g++
CXXFLAGS = -g -std=c++14 -Wall -MMD
EXEC = cc3k+

PLAYERS = player.o human.o dwarf.o orc.o elves.o
ENEMIES = vampire.o troll.o goblin.o werewolf.o phoenix.o dragon.o merchant.o
CELLS = doorway.o passage.o floorTile.o 
ITEMS = item.o treasure.o potion.o
CONTROLLERS = game.o factory.o floor.o
INTERFACE = main.o textDisplay.o
OBJECTS = ${INTERFACE} ${CONTROLLERS} ${CELLS} ${PLAYERS} ${ENEMIES} ${ITEMS}
DEPENDS = ${OBJECTS:.o=.d}

${EXEC}: ${OBJECTS}
	${CXX} ${CXXFLAGS} ${OBJECTS} -o ${EXEC} -lncurses

-include ${DEPENDS}

.PHONY: clean
.PHONY: test
.PHONY: clear

clean:
	rm ${OBJECTS} ${EXEC} ${DEPENDS}

clear:
	rm ${OBJECTS} ${DEPENDS}
  
test:
	./runSuite suitea5.txt ./exec
