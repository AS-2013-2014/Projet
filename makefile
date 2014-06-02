objects = main.o src/Game.o src/Scene.o src/Segment.o src/HitBox.o  \
		  src/Entity.o src/Solid.o src/Platform.o src/Character.o src/Graphic.o

edit : $(objects)
	g++ -o run $(objects) -lsfml-graphics -lsfml-window -lsfml-system

$(objects) : include/*.hpp

.PHONY : clean

clean :
	rm $(objects) 2> /dev/null
