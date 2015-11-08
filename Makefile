LIBS=-lsfml-graphics -lsfml-window -lsfml-system

all: AnterficialAntelligence

Game.o: Game.cpp
	g++ -c Game.cpp -o Game.o

AnterficialAntelligence: Game.o
	@echo "** Build Happening **"
	g++ -o AnterficialAntelligence Game.o ${LIBS}

clean: 
	@echo "** Removing executable and objects **"
	rm -f AnterficialAntelligence *.o

install:
	@echo "** Installing to /usr/bin **"
	cp AnterficialAntelligence /usr/bin
	
uninstall:
	@echo "** Uninstalling /usr/bin/AnterficialIntelligence **"
	rm -f /usr/bin/AnterficialAntelligence

run:
	./AnterficialAntelligence
