CXX = g++
CXXFLAGS = -g -std=c++14 -Wall -MMD
EXEC = cc3k
<<<<<<< HEAD
OBJECTS = main.o textDisplay.o stuff.o character.o player.o dwarf.o
=======
OBJECTS = main.o textDisplay.o stuff.o character.o cell.o floor.o 
>>>>>>> 3f92f4a1337a21aee0ece751353affa43105e66a
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
