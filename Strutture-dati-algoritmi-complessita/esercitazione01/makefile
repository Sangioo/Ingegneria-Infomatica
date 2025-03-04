CC = g++
CFLAGS = -Wall -g
SRCS = bsort.c
OBJS = $(SRCS:.c=.o)
HEADERS = $(SRCS:.c=.h)
MAIN = main

all:    $(MAIN)



$(MAIN): $(OBJS) $(MAIN).c
	$(CC) $(CFLAGS) -o $(MAIN) $(MAIN).c $(OBJS)

%.o: %.c %.h
	g++ -c $(CFLAGS) $*.c -o $*.o

clean:
	$(RM) *.o $(MAIN)