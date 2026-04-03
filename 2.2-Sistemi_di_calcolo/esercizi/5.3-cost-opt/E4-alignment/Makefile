CC=gcc
CFLAGS=-O1

all: e4

e4:
	$(CC) $(CFLAGS) e4_main.c -o e4

.PHONY: test, clean

test:
	./e4 0
	./e4 1
	./e4 2
	./e4 3
	./e4 4
	./e4 5
	./e4 6
	./e4 7
	./e4 8

clean:
	rm -rf e4

