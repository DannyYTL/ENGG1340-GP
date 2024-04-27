FLAGS = -pedantic-errors -std=c++11
TARGET = main
OBJECTS = main.o board.o display.o file.o processing.o win.o in_main.o

main.o: main.cpp gaming.h
	@echo -n 'Preparing to go to the minefield'
	@g++ $(FLAGS) -c $<
	@echo -n .

board.o: board.cpp gaming.h
	@g++ $(FLAGS) -c $<
	@echo -n .

display.o: display.cpp gaming.h
	@g++ $(FLAGS) -c $<
	@echo -n .
	
file.o: file.cpp gaming.h
	@g++ $(FLAGS) -c $<
	@echo -n .

processing.o: processing.cpp gaming.h
	@g++ $(FLAGS) -c $<
	@echo -n .

win.o: win.cpp gaming.h
	@g++ $(FLAGS) -c $<
	@echo -n .

in_main.o: in_main.cpp display.cpp processing.cpp win.cpp file.cpp gaming.h
	@g++ $(FLAGS) -c $<
	@echo -n .

$(TARGET): $(OBJECTS)
	@g++ $(FLAGS) $(OBJECTS) -o $(TARGET)
	@echo .

clean:
	rm -f $(TARGET) $(OBJECTS) Record.txt main.tgz

tar:
	tar -czvf main.tgz *.cpp *.h Makefile

.PHONY: clean tar
