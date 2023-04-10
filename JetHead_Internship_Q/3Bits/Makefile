CC=g++
CFLAGS=-std=c++11 -Wall -Wextra -pedantic

all: 3bits

3bits: 3bits.o
	$(CC) $(CFLAGS) -o $@ $<

3bits.o: 3bits.cpp
	$(CC) $(CFLAGS) -c $<

clean:
	rm -f 3bits 3bits.o