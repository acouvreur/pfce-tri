CC=gcc
CFLAGS=-Wall -g -lm -std=c99 -O3
DEPS = generator.h tri.h test.h
OBJ = generator.o tri.o test.o main.o 

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

all: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)

clean:
	rm *.o