FLAGS = -pedantic-errors -std=c++11
TARGET = main
OBJECTS = main.o board.o display.o file.o processing.o win.o in_main.o


main.o: main.cpp gaming.h
	g++ $(FLAGS) -c $<

board.o: board.cpp gaming.h
	g++ $(FLAGS) -c $<

display.o: display.cpp gaming.h
	g++ $(FLAGS) -c $<

file.o: file.cpp gaming.h
	g++ $(FLAGS) -c $<

processing.o: processing.cpp gaming.h
	g++ $(FLAGS) -c $<

win.o: win.cpp gaming.h
	g++ $(FLAGS) -c $<

in_main.o: in_main.cpp display.cpp processing.cpp win.cpp file.cpp gaming.h
	g++ $(FLAGS) -c $<

Record.txt:
	echo > Record.txt

$(TARGET): $(OBJECTS)
	g++ $(FLAGS) $(OBJECTS) -o $(TARGET)
	./main

clean:
	rm -f *.o main
	rm -rf .vscode

tar:
	tar -czvf main.tgz *.cpp *.h

.PHONY: clean tar