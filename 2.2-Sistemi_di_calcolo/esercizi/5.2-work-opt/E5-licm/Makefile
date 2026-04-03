SCC=gcc
CFLAGS=-O1

all: e5 e5-licm e5-O3 e5-O3.s

e5:
	$(CC) $(CFLAGS) e5_main.c e5.c f.c -o e5

e5-licm:
	$(CC) $(CFLAGS) e5_main.c e5_licm.c f.c -o e5-licm

e5-O3:
	$(CC) -O3 e5_main.c e5.c f.c -o e5-O3

e5-O3.s:
	$(CC) -O3 e5.c -S -o e5-O3.s

.PHONY: test, clean

test:
	./e5
	./e5
	./e5
	./e5-licm
	./e5-licm
	./e5-licm
	./e5-O3
	./e5-O3
	./e5-O3
	
clean:
	rm -rf e5 e5-licm e5-O3 e5-O3.s

