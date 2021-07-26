# Source, Headers and Objects
S = ./src
H = ./include
O = ./obj

# Compilation
CC = clang
FLAGS = -Wall -Ofast

OBJECTS = ./obj/dictionary.o ./obj/reader.o

speller: main.o $(OBJECTS)
	$(CC) -I $(H) $^ -o $@

# Patterns 
./obj/%.o: ./src/%.c
	$(CC) -I $(H) -c $^ -o $@

%.o: %.c
	$(CC) -I $(H) -c $^ -o $@
