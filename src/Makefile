LIBS=-lsfml-graphics -lsfml-window -lsfml-audio -lsfml-system

#main
run: main.o Resources.o Audio.o Game.o Segment.o Scene.o Section.o Entity.o Platform.o
	g++ main.o Resources.o Audio.o Game.o Segment.o Scene.o Section.o Entity.o Platform.o -o run $(LIBS)

main.o: main.cpp
	g++ -c main.cpp -o main.o

#misc
Resources.o: misc/Resources.hpp misc/Resources.cpp 
	g++ -c misc/Resources.cpp -o Resources.o

Audio.o: audio/Audio.hpp audio/Audio.cpp
	g++ -c audio/Audio.cpp -o Audio.o


#game
Section.o: game/Section.cpp game/Section.hpp
	g++ -c game/Section.cpp -o Section.o

Segment.o: game/Segment.cpp game/Segment.hpp
	g++ -c game/Segment.cpp -o Segment.o

Game.o: game/Game.cpp game/Game.hpp
	g++ -c game/Game.cpp -o Game.o

Entity.o: game/Entity.cpp game/Entity.hpp
	g++ -c game/Entity.cpp -o Entity.o

Scene.o: game/Scene.cpp game/Scene.hpp
	g++ -c game/Scene.cpp -o Scene.o

Platform.o: game/entities/Platform.cpp game/entities/Platform.hpp
	g++ -c game/entities/Platform.cpp -o Platform.o

