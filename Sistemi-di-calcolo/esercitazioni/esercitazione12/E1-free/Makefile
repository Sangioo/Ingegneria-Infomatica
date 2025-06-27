CC=gcc
CFLAGS=-Wno-deprecated-declarations -O1

all: e1

e1: e1_main.c e1.c e1.h
	$(CC) $(CFLAGS) e1_main.c e1.c -o e1

.phony: clean
	
clean:
	rm -rf e1
