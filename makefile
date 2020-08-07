# $ make
# $ ./2_opt

CC = clang++
CFLAGS = -c
DEBUG = -Wall -Werror -Wextra
THREAD = -pthread
SFML = -lsfml-graphics -lsfml-window -lsfml-system

all: 2_opt

debug: DEBUG += -g -fsanitize=address
debug: all

2_opt: main.o chemin.o
	$(CC) $(DEBUG) $(THREAD) main.o chemin.o -o 2_opt $(SFML)

chemin.o : chemin.cpp chemin.h
	$(CC) $(CFLAGS) $(DEBUG) $(THREAD) chemin.cpp


clean:
	\rm *.o 2_opt

run: all
run:
	./2_opt