CC=gcc
CFLAGS=-Wall -lm -std=c99
DEPS = generator.h tri.h
OBJ = generator.o tri.o main.o 

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

all: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)

clean:
	rm *.o