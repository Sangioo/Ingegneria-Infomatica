#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

#include "auxiliary.h"

// *ESERCIZI
/*ESERCIZIO 1*/
// Scrivere la funzione 
// Mat* mat_alloc(int rows, int cols);
// che, dato in ingresso il numero di righe rows ed il numero di colonne cols, allochi e restituisca una struttura Mat
// contenente una matrice di dimensione rows x cols. La matrice deve essere memorizzata come array di puntatori alle righe della matrice stessa.
Mat* mat_alloc(int rows, int cols) {
	Mat* m = (Mat *)malloc(sizeof(Mat));

	m->rows = rows;
	m->cols = cols;

	m->mat = (float **) malloc(sizeof(float*) * m->rows);

	for (int i=0; i<m->rows; i++) {
		m->mat[i] = (float *) malloc(sizeof(float) * m->cols);
	}

	return m;
}

/*ESERCIZIO 2*/
// Scrivere la funzione
// void mat_free(Mat *m);
// che, data in ingresso una struttura Mat m contenente una matrice, deallochi completamente la matrice m.
void mat_free(Mat *m) {
	if (m == NULL) {
		return;
	}
	for (int i=0; i<m->rows; i++) {
		free(m->mat[i]);
	}
	free(m->mat);
	free(m);
}

/*ESERCIZIO 3*/
// Scrivere la funzione
// void mat_print(Mat *m);
// che, data in ingresso una struttura Mat m contenente una matrice, stampi la matrice.
void mat_print(Mat *m) {
	if (m == NULL) {
		return;
	}
	printf("%d %d\n", m->rows, m->cols);

	for (int i=0; i<m->rows; i++) {
		for (int j=0; j<m->cols; j++) {
			printf("%f\t", m->mat[i][j]);
		}
		printf("\n");
	}
}

/*ESERCIZIO 4*/
// Scrivere la funzione
// Mat * mat_clone(Mat *m);
// che, data in ingresso una una una struttura Mat m contenente una matrice, allochi una
// nuova struttura ed una nuova matrice delle stesse dimensioni di m, vi copi il contenuto di m e ne restituisca il puntatore.
Mat * mat_clone(Mat *m) {
	Mat* x = (Mat *) malloc(sizeof(Mat));

	x->rows = m->rows;
	x->cols = m->cols;
	x->mat = (float **) malloc(sizeof(float *) * x->rows);
	for (int i=0; i<x->rows; i++) {
		x->mat[i] = (float *) malloc(sizeof(float) * x->cols);
		for (int j=0; j<x->cols; j++) {
			x->mat[i][j] = m->mat[i][j];
		}
	}

	return x;
}

/*ESERCIZIO 5*/
// Scrivere la funzione
// bool mat_is_symmetric(Mat *m);
// che data in ingresso una struttura Mat m contenente una matrice, verifichi che m sia simmetrica o meno.
// Se m e' simmetrica la funzione deve restituire true in uscita, altrimenti deve restituire false.
// Si ricorda che una matrice e' simmetrica se ogni elemento m_ij e' uguale all'elemento m_ji.
bool mat_is_symmetric(Mat *m) {
	for (int i=0; i<m->rows; i++) {
		for (int j=0; j<m->cols; j++) {
			if(m->mat[i][j] != m->mat[j][i]) {
				return false;
			}
		}
	}

	return true;
}

/*ESERCIZIO 6*/
// Scrivere la funzione
// void mat_normalize_rows(Mat *m);
// che, data in ingresso una struttura Mat m contenente una matrice, modifichi m in modo da normalizzare le righe.
// Si ricorda che la normalizzazione di una riga si ottiene dividendo tutti gli elementi della riga per il modulo della riga stessa.
// Suggerimento: svolgere la variante in cui la matrice normalizzata viene restituita come valore di ritorno, invece di modificare m.
void mat_normalize_rows(Mat *m) {
	float max;
	for (int i=0; i<m->rows; i++) {
		max = m->mat[i][0];
		for (int j=0; j<m->cols; j++) {
			if (m->mat[i][j] > max) {
				max = m->mat[i][j];
			}
		}

		for (int j=0; j<m->cols; j++) {
			m->mat[i][j] /= max;
		}
	}
}

/*ESERCIZIO 7*/
// Scrivere la funzione 
// Mat* mat_sum(Mat *m1, Mat *m2);
// che, date in ingresso due strutture Mat m1 e Mat m2 contenenti due matrici, allochi e restituisca la somma delle suddette matrici.
// Nel caso non fosse possibile eseguire la somma (per esempio, se le dimensioni delle due matrici di input non sono uguali),
// la funzione deve stampare a schermo un messaggio di errore e ritornare NULL.
Mat* mat_sum(Mat *m1, Mat *m2) {
	if (m1->rows != m2->rows || m1->cols != m2->cols) {
		printf("IMPOSSIBILE CALCOLARE LA SOMMA DELLE MATRICI DATE IN INPUT\n");
		return NULL;
	}

	Mat *sum = mat_alloc(m1->rows, m1->cols);
	for (int i=0; i<sum->rows; i++) {
		for (int j=0; j<sum->cols; j++) {
			sum->mat[i][j] = m1->mat[i][j] + m2->mat[i][j];
		}
	}

	return sum;
}

/*ESERCIZIO 7b*/
// Svolgere anche una variante in cui si definisce la funzione Mat* mat_average(Mat *m1, Mat *m2) che, invece di
// calcolare la somma tra le due matrici, ne calcola la media.
Mat* mat_avg(Mat *m1, Mat *m2) {
	if (m1->rows != m2->rows || m1->cols != m2->cols) {
		printf("IMPOSSIBILE CALCOLARE LA MEDIA DELLE MATRICI DATE IN INPUT\n");
		return NULL;
	}

	Mat *avg = mat_alloc(m1->rows, m1->cols);
	for (int i=0; i<avg->rows; i++) {
		for (int j=0; j<avg->cols; j++) {
			avg->mat[i][j] = (m1->mat[i][j] + m2->mat[i][j])/2.0;
		}
	}

	return avg;
}

/*ESERCIZIO 8*/
// Scrivere una funzione:
// Mat* mat_product(Mat *m1, Mat *m2);
// che, date in ingresso due strutture Mat m1 e Mat m2 contenenti due matrici, allochi e restituisca il prodotto delle suddette matrici.
// Nel caso non fosse possibile eseguire il prodotto (per esempio, se le dimensioni delle due matrici di input non consentono il prodotto),
// la funzione deve stampare a schermo un messaggio di errore e ritornare NULL.
Mat* mat_product(Mat *m1, Mat *m2) {
	if (m1->cols != m2->rows) {
		printf("IMPOSSIBILE CALCOLARE IL PRODOTTO DELLE MATRICI DATE IN INPUT\n");
		return NULL;
	}

	Mat *prod = mat_alloc(m1->rows, m2->cols);
	for (int i=0; i<prod->rows; i++) {
		for (int j=0; j<prod->cols; j++) {
			for (int k=0; k<m1->rows; k++) {
				prod->mat[i][j] += m1->mat[i][k] * m2->mat[k][j];
			}
		}
	}

	return prod;
}

/*ESERCIZIO 9*/
// Scrivere una funzione:
// Mat* game_of_life(Mat* mat);
// Basata sull’algoritmo di Conway che implementa una iterazione del gioco.
// La funzione deve prendere in input una matrice al tempo i e restituire la matrice al tempo i+1.
// Indicare una cella viva con il float 1, e una cella morta con 0.
// Scrivere un main per testare la funzione. Suggerimento: il main potrebbe usare mat_alloc per creare una matrice iniziale,
// e mat_free, mat_print ad ogni chiamata di game_of_life per il normale avanzamento.
Mat* game_of_life(Mat* mat) {
	int neighbors = 0;
	for (int i=0; i<mat->rows; i++) {
		for (int j=0; j<mat->cols; j++) {
			neighbors = 0;
			if (i-1>=0 && j-1>=0 && mat->mat[i-1][j-1] == 1) {
				neighbors++;
			}
			if (i-1>=0 && mat->mat[i-1][j] == 1) {
				neighbors++;
			}
			if (i-1>=0 && j+1<mat->cols && mat->mat[i-1][j+1] == 1) {
				neighbors++;
			}
			if (j-1>=0 && mat->mat[i][j-1] == 1) {
				neighbors++;
			}
			if (j+1<mat->cols && mat->mat[i][j+1] == 1) {
				neighbors++;
			}
			if (i+1<mat->rows && j-1>=0 && mat->mat[i+1][j-1] == 1) {
				neighbors++;
			}
			if (i+1<mat->rows && mat->mat[i+1][j] == 1) {
				neighbors++;
			}
			if (i+1<mat->rows && j+1<mat->cols && mat->mat[i+1][j+1] == 1) {
				neighbors++;
			}

			if (mat->mat[i][j] == 1) {
				if (neighbors != 2 && neighbors != 3) {
					mat->mat[i][j] = 0;
				}
			} else if (mat->mat[i][j] == 0) {
				if (neighbors == 3) {
					mat->mat[i][j] = 1;
				}
			}
		}
	}
	return mat;
}

/*ESERCIZIO 10*/
// Scrivere una funzione
// void sort_strings(char **array);
// che riceve in input un array di N stringhe. L’elenco è terminato da un puntatore NULL in posizione array[N].
// La funzione deve modificare l’array, ordinando le stringhe per lunghezza: in array[0] ci deve essere la
// stringa più lunga e in array[len-1] la più corta.
void sort_strings(char **array) {
	int len = 0;
	char *tmp;
	while (array[len] != NULL) {
		len++;
	}

	for (int i=0; i<len; i++) {
		for (int j=i+1; j<len; j++) {
			if (mystrlen(array[i]) < mystrlen(array[j])) {
				tmp = array[i];
				array[i] = array[j];
				array[j] = tmp;
			}
		}
	}
}



// *FUNZIONI DI TEST
void test1() {
	int rows = 3, cols = 5;
	Mat* result = mat_alloc(rows, cols);
	mat_init(result);

	printf("TEST ESERCIZIO 1\n");
	mat_print(result);
}

void test2() {
	int rows = 3, cols = 5;
	Mat* m = mat_alloc(rows, cols);

	printf("\nTEST ESERCIZIO 2\n");
	mat_free(m);
}

void test3() {
	int rows = 3, cols = 5;
	Mat* m = mat_alloc(rows, cols);
	mat_init(m);

	printf("\nTEST ESERCIZIO 3\n");
	mat_print(m);
}

void test4() {
	int rows = 3, cols = 5;
	Mat* m = mat_alloc(rows, cols);
	mat_init(m);

	printf("\nTEST ESERCIZIO 4\n");
	mat_print(m);

	Mat* m_clone = mat_clone(m);
	mat_print(m_clone);
}

void test5() {
	int rows = 5, cols = 5;
	Mat* m = mat_alloc(rows, cols);
	mat_init_symmetric(m);

	printf("\nTEST ESERCIZIO 5\n");
	mat_print(m);
	printf("simmetrica: %d\n", mat_is_symmetric(m));
}

void test6() {
	int rows = 3, cols = 5;
	Mat* m = mat_alloc(rows, cols);
	mat_init(m);

	printf("\nTEST ESERCIZIO 6\n");
	mat_print(m);

	mat_normalize_rows(m);
	mat_print(m);
}

void test7() {
	int rows = 3, cols = 5;
	Mat* m1 = mat_alloc(rows, cols);
	mat_init(m1);

	Mat* m2 = mat_alloc(rows, cols);
	mat_init(m2);

	printf("\nTEST ESERCIZIO 7\n");
	mat_print(m1);
	mat_print(m2);

	Mat* sum = mat_sum(m1, m2);
	mat_print(sum);
}

void test7b() {
	int rows = 3, cols = 5;
	Mat* m1 = mat_alloc(rows, cols);
	mat_init(m1);

	Mat* m2 = mat_alloc(rows, cols);
	mat_init(m2);

	printf("\nTEST ESERCIZIO 7b\n");
	mat_print(m1);
	mat_print(m2);

	Mat* avg = mat_avg(m1, m2);
	mat_print(avg);
}

void test8() {
	Mat *m1 = mat_alloc(3, 3);
	mat_init(m1);
	Mat *m2 = mat_alloc(3, 2);
	mat_init(m2);

	printf("TEST ESERCIZIO 8\n");
	mat_print(m1);
	mat_print(m2);

	Mat *prod = mat_product(m1, m2);
	mat_print(prod);
}

void test9() {
	Mati *m = mat_alloc(4, 4);
	mat_init_bool(m);

	printf("\nTEST ESERCIZIO 9\n");
	mat_print_int(m);
}

void test10() {

}

void test11() {

}

void test12() {

}