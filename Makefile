CXX = g++
CXXFLAGS = -g -std=c++14 -Wall -MMD
EXEC = cc3k
OBJECTS = main.o textDisplay.o stuff.o character.o cell.o floor.o 
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
