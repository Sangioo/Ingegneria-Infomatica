CC=gcc
CFLAGS=-O1 -Wall

e2: e2_main.c e2.c e2_opt.c
	$(CC) $(CFLAGS) e2_main.c e2.c e2_opt.c -o e2

.phony: clean

clean:
	rm -rf e2
