LIBS=-lsfml-graphics -lsfml-window -lsfml-audio -lsfml-system

run: main.o Resources.o
	g++ main.o Resources.o -o run $(LIBS)

main.o: main.cpp
	g++ -c main.cpp -o main.o

Resources.o: misc/Resources.hpp misc/Resources.cpp
	g++ -c misc/Resources.cpp -o Resources.o
