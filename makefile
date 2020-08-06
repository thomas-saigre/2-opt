# $ make
# $ ./2_opt

CC = g++
CFLAGS = -c
DEBUG = -g -Wall -Werror -Wextra
SFML = -lsfml-graphics -lsfml-window -lsfml-system

all: 2_opt

2_opt: main.o chemin.o
	$(CC) $(DEBUG) main.o chemin.o -o 2_opt $(SFML)

chemin.o : chemin.cpp
	$(CC) $(CFLAGS) $(DEBUG) chemin.cpp


clean:
	\rm *.o 2_opt
