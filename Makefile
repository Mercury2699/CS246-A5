CXX = g++
CXXFLAGS = -g -std=c++14 -Wall -MMD
EXEC = cc3k

OBJECTS = main.o textDisplay.o doorway.o passage.o floorTile.o character.o player.o enemy.o potion.o restorHP.o poisonHP.o boostAtk.o boostDef.o woundAtk.o woundDef.o
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
