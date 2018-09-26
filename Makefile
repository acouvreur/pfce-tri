CC=gcc
CFLAGS=-I.
DEPS = generator.h tri.h
OBJ = generator.o tri.o main.o 

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

all: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)