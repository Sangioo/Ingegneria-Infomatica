#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

// ES 6
// Scrivere la funzione
// int * allocaInt();
// che alloca dinamicamente in memoria un intero e ne restituisce in uscita il puntatore.
int* allocaInt() {
	int* p = (int *) malloc(sizeof(int));

	return p;
}

// ES 7
// Scrivere la funzione 
// void printInt(int *i1, int *i2);
// che, dati in input due puntatori ad intero ne stampa i valori.
void printInt(int *i1, int *i2) {
	printf("i1_7: %d\ti2_7: %d\n", *i1, *i2);
	return;
}

// ES 8
// scrivere tre funzioni:
// bool soluzioneEquazione(int a, int b, int c, double* x1, double* x2);
// double * soluzioneEquazionePtr(int a, int b, int c);
// void * soluzioneEquazionePtrComplessi(int a, int b, int c);
// che, dati in input tre interi, risolvano l’equazione di secondo grado :
// ax^2 + bx + c = 0
// e:
// - nella prima funzione, restituisce true se la soluzione esiste e falso altrimenti, e i risultati come parametri di output x1 e x2
// - nella seconda funzione, restituisce il puntatore ad una zona di memoria allocata dinamicamente contenente i due risultati,
// 	 oppure NULL se non esiste soluzione nel campo dei reali
// - nella terza funzione, restituisce il puntatore ad una zona di memoria che contiene nel primo byte un carattere che indica il
//   tipo di soluzione (reale o complessa) e i successivi byte che contengono un opportuno numero di valori double contenenti i risultati.
bool soluzioneEquazione(int a, int b, int c, double* x1, double* x2) {
	double delta = b*b - 4*a*c;

	if (delta < 0) {
		*x1 = 0;
		*x2 = 0;
		return false;
	} else {
		*x1 = (-b + sqrt(delta))/2*a;
		*x2 = (-b - sqrt(delta))/2*a;
		return true;
	}
}
double* soluzioneEquazionePtr(int a, int b, int c) {
	double *result = (double *) malloc(sizeof(double) * 2);
	double delta = b*b - 4*a*c;

	if (delta < 0) {
		return NULL;
	} else {
		*result = (-b + sqrt(delta))/2*a;
		*(result + 1) = (-b - sqrt(delta))/2*a;
		return result;
	}
}
void* soluzioneEquazionePtrComplessi(int a, int b, int c) {
	void *result;
	char *campo;
	double delta = b*b - 4*a*c, *solve;

	if (delta < 0) {
		result = malloc(sizeof(char) + sizeof(double) * 2);
		campo = (char *)result;
		*campo = 'C';
		solve = (double *)(campo + 1);

		double modulo = fabs(delta);
		*solve = -b / 2*a;
		*(solve + 1) = sqrt(modulo) / 2*a;
	} else if (fabs(delta - 0.0) < 1e-6) {
		result = malloc(sizeof(char) + sizeof(double));
		campo = (char *)result;
		*campo = 'R';
		solve = (double *) (campo + 1);

		*solve = -b / 2*a;
	} else {
		result = malloc(sizeof(char) + sizeof(double) * 2);
		campo = (char *)result;
		*campo = 'R';
		solve = (double *) (campo + 1);

		*solve = (-b + sqrt(delta)) / 2*a;
		*(solve + 1) = (-b - sqrt(delta)) / 2*a;
	}

	return result;
}

// ES 8b
// Scrivere la funzione
// void printSoluzione(void *soluzione);
// che, dato in ingresso l’output della funzione precedente ne stampi il risultato.
void printSoluzione(void *soluzione) {
	char *campo = (char *)soluzione;
	double *zeri = (double *)(campo + 1);
	if (*campo == 'R') {
		printf("soluzione nel campo reale\n");
		printf("zeri della funzione: %lf %lf\n", *zeri, *(zeri + 1));
	} else {
		printf("soluzione nel campo complesso\n");
		printf("zeri della funzione: %lf ±%lfi\n", *zeri, *(zeri + 1));
	}
	return;
}

// ES 9
// Scrivere la funzione
// int MCD(int i1, int i2);
// che, dati in input due interi (i1,i2)calcoli il massimo comun divisore e ritorni il risultato.
int MCD(int i1, int i2) {
	int min;
	if (i1 < i2) {
		min = i1;
	} else {
		min = i2;
	}

	for (int i = min; i > 0; i--) {
		if (i1%i == 0 && i2%i == 0) {
			return i;
		}
	}
}

// ES 10
// Scrivere la funzione
// int mcm(int i1, int i2);
// che, dati in input due interi (i1,i2) calcoli il minimo comune multiplo e ritorni il risultato.
// Suggerimento: si ricorda che mcm(a,b) = a*b / MCD(a,b)
int mcm(int i1, int i2) {
	return i1 * i2 / MCD(i1, i2);
}

// ES 11
// Scrivere la funzione
// void conversioneTemperatura(float t, char c);
// Che prende in input una temperatura t e una scala di riferimento data dal char c. La funzione deve effettuare la conversione nelle altre scale, esattamente come nell’***** esercizio 3.3 *****.
// Variante: scrivere una funzione che restituisca i risultati come parametri di output.
void conversioneTemperatura(float t, char c, float* resK, float* resC, float* resF) {
	if (c == 'C') {
		*resC = t;
		*resK = t + 273.15f;
		*resF = (t * 1.8f) + 32;
	} else if (c == 'K') {
		*resC = t - 273.15f;
		*resK = t;
		*resF = ((t - 273.15f) * 1.8f) + 32;
	} else if (c == 'F') {
		*resC = (t - 32) * 5/9;
		*resK = (t - 32) * 5/9 + 273.15f;
		*resF = t;
	}
	return;
}

// ES 12
// Scrivere la funzione
// void* conversioneTemperaturaP(float *t, char c);
// che, dati in input un puntatore a float t e un char c, svolga lo stesso compito della funzione precedente.
// Inoltre, deve ritornare il puntatore alla memoria allocata contenente la soluzione (il risultato della conversione in entrambe le scale).
// Le due conversioni risultanti devono essere salvate in una zona di memoria allocata dinamicamente con un'unica chiamata alla funzione malloc().
void* conversioneTemperaturaP(float *t, char c) {
	void* res = malloc(sizeof(float) * 2 + sizeof(char) * 2);
	char *res1c = (char *)res;
	float *res1 = (float *)(res1c + 1);
	char *res2c = (char *)(res1 + 1);
	float *res2 = (float *)(res2c + 1);

	if (c == 'C') {
		*res1c = 'K';
		*res1 = *t + 273.15f;
		*res2c = 'F';
		*res2 = (*t * 1.8f) + 32;
	} else if (c == 'K') {
		*res1c = 'C';
		*res1 = *t - 273.15f;
		*res2c = 'F';
		*res2 = ((*t - 273.15f) * 1.8f) + 32;
	} else if (c == 'F') {
		*res1c = 'C';
		*res1 = (*t - 32) * 5/9;
		*res2c = 'K';
		*res2 = (*t - 32) * 5/9 + 273.15f;
	}
	return res;
}

// ES 13
// Scrivere la funzione
// void printConversione(void *conversioni);
// che, dato in ingresso l’output della funzione precedente ne stampi il risultato.
// N.B. nella zona di memoria conversioni sono memorizzati in maniera contigua sia il valore numerico che la scala di entrambe le conversioni.
void printConversione(void *conversioni) {
	char *c1 = (char *)conversioni;
	float *t1 = (float *)(c1 + 1);
	char *c2 = (char *)(t1 + 1);
	float *t2 = (float *)(c2 + 1);

	printf("temperatura in %c: %f\n", *c1, *t1);
	printf("tempeartura in %c: %f\n", *c2, *t2);

	return;
}

int main() {
	// ES 6
	printf("***** ESERCIZIO 6:  *****\n");
	int *p1_6;
	p1_6 = allocaInt();
	printf("p1_6: %x\n", p1_6);


	// ES 7
	printf("\n\n***** ESERCIZIO 7:  *****\n");
	int i1_7 = 10, i2_7 = 20;
	printInt(&i1_7, &i2_7);


	// ES 8
	printf("\n\n***** ESERCIZIO 8:  *****\n");
	int a_8 = 1, b_8 = 2, c_8 = 3;
	double x1_8, x2_8, *sol2_8, *zeri_8;
	bool sol1_8;
	void *sol3_8;
	char *campoSol3_8;

	sol1_8 = soluzioneEquazione(a_8, b_8, c_8, &x1_8, &x2_8);
	if (sol1_8) {
		printf("1) zeri della funzione: %lf %lf\n", x1_8, x2_8);
	} else {
		printf("1) la funzione non tocca l'asse x\n");
	}

	sol2_8 = soluzioneEquazionePtr(a_8, b_8, c_8);
	if (sol2_8) {
		printf("2) zeri della funzione: %lf %lf\n", *sol2_8, *(sol2_8 + 1));
	} else {
		printf("2) la funzione non tocca l'asse x\n");
	}

	sol3_8 = soluzioneEquazionePtrComplessi(a_8, b_8, c_8);
	campoSol3_8 = (char *)sol3_8;
	zeri_8 = (double *)(campoSol3_8 + 1);
	if (*campoSol3_8 == 'R') {
		printf("3) soluzione nel campo reale\n");
		printf("   zeri della funzione: %lf %lf\n", *zeri_8, *(zeri_8 + 1));
	} else {
		printf("3) soluzione nel campo complesso\n");
		printf("   zeri della funzione: %lf ±%lfi\n", *zeri_8, *(zeri_8 + 1));
	}


	// ES 8b
	printf("\n\n***** ESERCIZIO 8b: *****\n");
	printSoluzione(sol3_8);


	// ES 9
	printf("\n\n***** ESERCIZIO 9:  *****\n");
	int i1_9 = 7, i2_9 = 24;
	int mcd = MCD(i1_9, i2_9);

	printf("i1_9: %d \ti2_9: %d\n", i1_9, i2_9);
	printf("MCD: %d\n", mcd);

	// ES 10
	printf("\n\n***** ESERCIZIO 10: *****\n");
	int i1_10 = 7, i2_10 = 24;
	int m = mcm(i1_10, i2_10);

	printf("i1_10: %d\ti2_10: %d\n", i1_10, i2_10);
	printf("mcm: %d\n", m);


	// ES 11
	printf("\n\n***** ESERCIZIO 11: *****\n");
	float temp_11 = 20, resK_11, resC_11, resF_11;
	char scala_11 = 'F';

	printf("temperatura input in %c: %f\n\n", scala_11, temp_11);
	conversioneTemperatura(temp_11, scala_11, &resK_11, &resC_11, &resF_11);
	printf("temperatura in K: %f\n", resK_11);
	printf("temperatura in C: %f\n", resC_11);
	printf("temperatura in F: %f\n", resF_11);


	// ES 12
	printf("\n\n***** ESERCIZIO 12: *****\n");
	float temp_12 = 12;
	char scala_12 = 'C';

	printf("temperatura in %c: %f\n", scala_12, temp_12);
	void *conversioni_12 = conversioneTemperaturaP(&temp_12, scala_12);


	// ES 13
	printf("\n\n***** ESERCIZIO 13: *****\n");
	printConversione(conversioni_12);


	return 0;
}