main.exe: animal.o monde.o main.o
	g++ animal.o monde.o main.o -o world.exe -lm
animal.o: animal.cpp animal.hpp
	g++ -g -c animal.cpp -o animal.o -lm
monde.o: monde.cpp monde.hpp
	g++ -g -c monde.cpp -o monde.o -lm
main.o: main.cpp animal.hpp monde.hpp
	g++ -g -c main.cpp -o main.o
clean:
	rm *.o world.exe