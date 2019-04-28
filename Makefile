CXX = g++
CXXFLAGS = -Wall -MMD
EXEC = quadris
OBJECTS = main.o Score.o Board.o block.o iblock.o jblock.o lblock.o oblock.o posn.o sblock.o tblock.o zblock.o level.o level0.o level1.o level2.o level3.o 
DEPENDS = ${OBJECTS:.o=.d}

${EXEC}: ${OBJECTS}
	${CXX} ${CXXFLAGS} ${OBJECTS} -o ${EXEC}

-include ${DEPENDS}

.PHONY: clean

clean:
	rm ${OBJECTS} ${EXEC} ${DEPENDS}
