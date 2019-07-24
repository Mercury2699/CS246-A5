CXX = g++
CXXFLAGS = -g -std=c++14 -Wall -MMD
EXEC = cc3k

PLAYERS = player.o human.o dwarf.o orc.o elves.o
POTIONS = potion.o
EMENIES = vampire.o troll.o werewolf.o phoenix.o dragon.o merchant.o
CELLS = doorway.o passage.o floorTile.o 
ITEMS = compass.o barrierSuit.o treasure.o
CONTROLLERS = floor.o factory.o
OBJECTS = main.o textDisplay.o treasure.o ${POTIONS} ${PLAYERS}
DEPENDS = ${OBJECTS:.o=.d}

${EXEC}: ${OBJECTS}
	${CXX} ${CXXFLAGS} ${OBJECTS} -o ${EXEC}

-include ${DEPENDS}

.PHONY: clean
.PHONY: test

clean:
	rm ${OBJECTS} ${EXEC} ${DEPENDS}
  
test:
	./runSuite suitea5.txt ./exec
