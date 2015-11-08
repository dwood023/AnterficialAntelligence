LIBS=-lsfml-graphics -lsfml-window -lsfml-system
SRC=src
OBJ=obj
BIN=bin

all: AnterficialAntelligence

Game.o: ${SRC}/Game.cpp
	g++ -c ${SRC}/Game.cpp -o ${OBJ}/Game.o

AnterficialAntelligence: ${OBJ}/Game.o
	@echo "** Build Happening **"
	g++ -o ${BIN}/AnterficialAntelligence ${OBJ}/Game.o ${LIBS}

clean: 
	@echo "** Removing executable and objects **"
	rm -f ${BIN}/AnterficialAntelligence ${OBJ}/*.o

install:
	@echo "** Installing to /usr/bin **"
	cp ${BIN}/AnterficialAntelligence /usr/bin
	
uninstall:
	@echo "** Uninstalling /usr/bin/AnterficialIntelligence **"
	rm -f /usr/bin/AnterficialAntelligence

run:
	./${BIN}/AnterficialAntelligence
