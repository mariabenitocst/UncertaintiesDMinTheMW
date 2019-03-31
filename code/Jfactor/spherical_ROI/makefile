CC = g++
IDIR =/usr/local/include
LDIR =/usr/local/lib
current_dir = $(shell pwd)
CFLAGS = -Wall -ansi -O3 -I$(IDIR) -I$(current_dir)/../include/ -c 
LFLAGS = -L$(LDIR) -lm  -lcuba -lgsl -lgslcblas
theta  = 1.


all: Jfactor

Jfactor: Jfactor.o
	$(CC) $(LFLAGS) -o Jfactor Jfactor.o Jfactor_grid.o

Jfactor.o: Jfactor.cpp Jfactor_grid.cpp
	$(CC) $(CFLAGS) Jfactor.cpp
	$(CC) $(CFLAGS) Jfactor_grid.cpp

run:
	./Jfactor 0.1 $(theta)
	./Jfactor 0.2 $(theta)
	./Jfactor 0.3 $(theta)
	./Jfactor 0.4 $(theta)
	./Jfactor 0.5 $(theta)
	./Jfactor 0.6 $(theta)
	./Jfactor 0.7 $(theta)
	./Jfactor 0.8 $(theta)
	./Jfactor 0.9 $(theta)
	./Jfactor 1.0 $(theta)
	./Jfactor 1.1 $(theta)
	./Jfactor 1.2 $(theta)
	./Jfactor 1.3 $(theta)
	./Jfactor 1.4 $(theta)
	./Jfactor 1.5 $(theta)


clean:
	rm *.o Jfactor
