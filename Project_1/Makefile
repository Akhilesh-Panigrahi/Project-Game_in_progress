# executable file to create and its dependancies
prog : driver.o Files.o
	g++ -std=c++11 -o prog driver.o Files.o

# file dependencies
driver_phase2.o : Files.h
	g++ -std=c++11 -c driver.cpp

Files.o : Files.h
	g++ -std=c++11 -c Files.cpp

# remove all object and executable files
clean:
	rm -f *.o
	rm prog