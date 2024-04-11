CC=g++
CFLAGS= -I. -s -Werror=return-type
OBJS=functions.o main.o auxiliary.o
TGT=main

all: $(TGT)

%.o: %.c $(DEPS)
	$(CC) -c $(CFLAGS) -o $@ $<
	strip -x $@

$(TGT):	$(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

clean:
	rm -rf $(OBJS) *~ $(TGT)


.PHONY:	clean
