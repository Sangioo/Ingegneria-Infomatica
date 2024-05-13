
#include <stdio.h>
#include <stdlib.h>

#include "aux.h"

#define NUMTESTDET1 3 
#define NUMTESTDET2 0 

// Dichiaro le funzioni di test
void test_one_21(TipoLista input1);
void test_one_22(TipoLista* input1, int input2);
TipoLista array2List(T* array, int len);


TipoLista randomList(int minLen, int maxLen, int min, int max){
	int len = (rand() % (maxLen +1 -minLen)) + minLen;

	TipoLista list = NULL;

	for(int j=0; j<len; j++)
			
		list = cons((rand() % (max+1-min)) + min, list );

	return list;
			
}

		
void buildInput21(TipoLista* lista1){
	//in base al numero dei test, modificare NUMTESTDET1
	int test1Lista1[] = {1,2,1,3,2,2,2};
	lista1[0] = array2List(test1Lista1, 7);
	
	
	int test2Lista1[] = {1,2,1,3};
	lista1[1] = array2List(test2Lista1, 4);
	

	int test3Lista1[] = {1,2,3,4,5};
	lista1[2] = array2List(test3Lista1, 5);

	
		
	

}
void buildRandomInput21(TipoLista* lista1, int n){
	
	for(int i=0; i<n; i++){
		
		lista1[i] = randomList(3, 9, 1, 5);
		

	}
}


void freeInput21(TipoLista* lista1){
	free(lista1);
}






int* buildRandomInput22(TipoLista** liste, int m){
	
	int* numListe = (int*)malloc(sizeof(int)*m);
	for(int i = 0; i<m; i++){
		numListe[i] = (rand() % 4)+2;
		liste[i] = (TipoLista*) malloc(sizeof(TipoLista*)*numListe[i]);

		
		for(int j=0; j<numListe[i]; j++){

			liste[i][j] = randomList(3,9,1,5);
		}

				
		
	}
	return numListe;
	
}

void freeInput22(TipoLista** liste, int* numListe, int m){
	//le cose commentate vengono deallocate dai test

	
	/*
	for(int i = 0; i<m; i++){
		//freelist(l2[i]);
		
		for(int j=0; j<numListe[i]; j++){
			freelist(liste[i][j]);
		}
		//free(liste[i]);
	}
	*/
	free(liste);
	free(numListe);
}

int main(void) {

	//srand(3842);
	srand(4110);
	//srand(4512);
	
	
	// Test per 2.1
	puts(">>> Esercizio 2.1\n");

	int n = 10;
	

	TipoLista* lista1 = (TipoLista*) malloc(sizeof(TipoLista)*n);

	buildInput21(lista1);
	buildRandomInput21(lista1+NUMTESTDET1, n-NUMTESTDET1);
	

	for(int i=0; i<n; i++){
		test_one_21(lista1[i]);
	}

	
	
	freeInput21(lista1);
	
	puts("\n\n>>> Esercizio 2.2");

	int m = 10;
	TipoLista** liste = (TipoLista**) malloc(sizeof(TipoLista*)*m);
	
	int* numListe = buildRandomInput22(liste+NUMTESTDET2, m-NUMTESTDET2);


	
	for(int i=0; i<m;i++){
		
		test_one_22(liste[i], numListe[i]);
	}
	
	freeInput22(liste, numListe, m);
	
}

// TODO: implementare queste funzioni
void test_one_21(TipoLista input1) {}
void test_one_22(TipoLista* input1, int input2) {}
TipoLista array2List(T* array, int len) {
	return NULL;
}