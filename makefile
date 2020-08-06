# $ make
# $ ./2_opt

CC = g++
CFLAGS = -c
DEBUG = -g -Wall -Werror -Wextra
SFML = -lsfml-graphics -lsfml-window -lsfml-system

all: 2_opt

2_opt: main.o villes.o
	$(CC) $(DEBUG) main.o villes.o -o 2_opt $(SFML)

villes.o : villes.cpp
	$(CC) $(CFLAGS) $(DEBUG) villes.cpp


clean:
	\rm *.o 2_opt
