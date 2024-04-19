FLAGS = -pedantic-errors -std=c++11
main.o: main.cpp
	g++ $(FLAGS) -c $<

main: main.o Record.txt
	g++ $(FLAGS) $^ -o $@
	./main

Record.txt:
	echo > Record.txt
