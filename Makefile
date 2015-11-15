COMPILER=g++ -std=c++11
LIBS:=-lsfml-graphics -lsfml-window -lsfml-system
SRCFILES:=${wildcard src/*.cpp}
OBJFILES := $(addprefix obj/,$(notdir $(SRCFILES:.cpp=.o)))
EXECUTABLE:=AntificialAntelligence

all: bin/$(EXECUTABLE)

bin/$(EXECUTABLE): $(OBJFILES)
	@echo "** Build Happening **"
	$(COMPILER) $(LIBS) -o $@ $^ 

obj/%.o: src/%.cpp
	$(COMPILER) -c -o $@ $<

clean: 
	@echo "** Removing executable and objects **"
	rm -f bin/$(EXECUTABLE) $(OBJFILES)

killswp:
	@echo "Cleaning up swp trash"
	rm src/.*.swp

install:
	@echo "** Installing to /usr/bin **"
	cp bin/$(EXECUTABLE) /usr/bin
	
uninstall:
	@echo "** Uninstalling /usr/bin/AntificialIntelligence **"
	rm -f /usr/bin/$(EXECUTABLE)

run:
	./bin/$(EXECUTABLE)
