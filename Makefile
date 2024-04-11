FLAGS = -pedantic-errors -std=c++11
main.o: main.cpp
	g++ $(FLAGS) -c $<

main: main.o
	g++ $(FLAGS) $^ -o $@
	./main
