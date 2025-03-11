main: main.c mat_sparsa_lista.o ran_mat
	./ran_mat 10 10
	g++ main.c -o main mat_sparsa_lista.o -g
	rm ran_mat

mat_sparsa_lista.o: mat_sparsa_lista.c mat_sparsa_lista.h
	g++ mat_sparsa_lista.c -c -g

ran_mat: ran_mat.c
	g++ ran_mat.c -o ran_mat

.PHONY: clean
clean:
	rm *.o mat.dat main
