CC=gcc
CFLAGS=-O1

all: e6 e6-unroll e6-O3 e6-O3.s

e6:
	$(CC) $(CFLAGS) e6_main.c e6.c -o e6

e6-unroll:
	$(CC) $(CFLAGS) e6_main.c e6_unroll.c -o e6-unroll

e6-O3:
	$(CC) -O3 e6_main.c e6.c -o e6-O3

e6-O3.s:
	$(CC) -O3 e6.c -S -o e6-O3.s

.PHONY: test, clean

test:
	./e6
	./e6
	./e6
	./e6-unroll
	./e6-unroll
	./e6-unroll
	./e6-O3
	./e6-O3
	./e6-O3

clean:
	rm -rf e6 e6-unroll e6-O3 e6-O3.s

