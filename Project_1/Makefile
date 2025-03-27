# executable file to create and its dependancies
prog : main.o player.o enemy.o obstacle.o objective.o map.o  game.o
	g++ -std=c++11 -o prog main.o player.o enemy.o obstacle.o objective.o map.o game.o

# file dependencies
main.o : player.h obstacle.h map.h game.h enemy.h
	g++ -std=c++11 -c main.cpp

player.o : player.h
	g++ -std=c++11 -c player.cpp

enemy.o : enemy.h
	g++ -std=c++11 -c enemy.cpp

obstacle.o : obstacle.h
	g++ -std=c++11 -c obstacle.cpp

objective.o : objective.h
	g++ -std=c++11 -c objective.cpp

map.o : map.h
	g++ -std=c++11 -c map.cpp

game.o : game.h
	g++ -std=c++11 -c game.cpp	

# remove all object and executable files
clean:
	rm -f *.o
	rm prog