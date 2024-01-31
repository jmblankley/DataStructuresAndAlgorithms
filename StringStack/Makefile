stacker: main.o Stack.o
	g++ -o stacker main.o Stack.o

main.o: main.cpp Stack.cpp
	g++ -c -Wall -ansi -pedantic -std=c++20 main.cpp

Stack.o: Stack.cpp Stack.hpp
	g++ -c -Wall -ansi -pedantic -std=c++20 Stack.cpp