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
	printf("i1: %d\ti2: %d\n", *i1, *i2);
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
	double delta = b*b - 4*a*c;

	if (delta < 0) {


		return NULL;
	} else if (fabs(delta - 0.0) < 1e-6) {
		result = malloc(sizeof(char) + sizeof(double));
		char *c = (char *)result;
		*c = 'R';
		double *resolve = (double *) (c + 1);

		*resolve = (-b)/2*a;

		return result;
	} else {
		result = malloc(sizeof(char) + sizeof(double) * 2);
		char *c = (char *)result;
		*c = 'R';
		double *resolve = (double *) (c + 1);

		*resolve = (-b + sqrt(delta))/2*a;
		*(resolve + 1) = (-b - sqrt(delta))/2*a;

		return result;
	}
}

// ES 8b
// Scrivere la funzione
// void printSoluzione(void *soluzione);
// che, dato in ingresso l’output della funzione precedente ne stampi il risultato.
// void printSoluzione(void *soluzione) {
// 	char *c = (char *)soluzione;
// 	double *s = (double *)(c + 1);

// 	int i = 0;
// 	while ((s + 1) != NULL) {
// 		printf("ris %d: %lf", i,  *(s + i));
// 		i++;
// 	}
// 	return;
// }

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
// Che prende in input una temperatura t e una scala di riferimento data dal char c. La funzione deve effettuare la conversione nelle altre scale, esattamente come nell’esercizio 3.3.
// Variante: scrivere una funzione che restituisca i risultati come parametri di output.
void conversioneTemperatura(float t, char c, float* resK, float* resC, float* resF) {
	if (c == 'C') {
		*resC = t;
		*resK = t + 273.15f;
		*resF = (t * 1.8f) + 32;
		printf("temperatura in Celsius: %lf\n", t);
		printf("temperatura in Kelvin: %lf\n", t + 273.15f);
		printf("temperatura in Fahrenheit: %lf\n", (t * 1.8f) + 32);
	} else if (c == 'K') {
		*resC = t - 273.15f;
		*resK = t;
		*resF = ((t - 273.15f) * 1.8f) + 32;
		printf("temperatura in Celsius: %lf\n", t - 273.15f);
		printf("temperatura in Kelvin: %lf\n", t);
		printf("temperatura in Fahrenheit: %lf\n", ((t - 273.15f) * 1.8f) + 32);
	} else if (c == 'F') {
		*resC = (t - 32) * 5/9;
		*resK = (t - 32) * 5/9 + 273.15f;
		*resF = t;
		printf("temperatura in Celsius: %lf\n", (t - 32) * 5/9);
		printf("temperatura in Kelvin: %lf\n", (t - 32) * 5/9 + 273.15f);
		printf("temperatura in Fahrenheit: %lf\n", t);
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
	void* res = malloc(sizeof(float) * 3);
	float *resC = (float *)res;
	float *resK = (float *)(resC + 1);
	float *resF = (float *)(resC + 2);
	if (c == 'C') {
		*resC = *t;
		*resK = *t + 273.15f;
		*resF = (*t * 1.8f) + 32;
	} else if (c == 'K') {
		*resC = *t - 273.15f;
		*resK = *t;
		*resF = ((*t - 273.15f) * 1.8f) + 32;
	} else if (c == 'F') {
		*resC = (*t - 32) * 5/9;
		*resK = (*t - 32) * 5/9 + 273.15f;
		*resF = *t;
	}
	return res;
}

int main() {
	// ES 6
	int *p1;
	p1 = allocaInt();
	printf("p1: %x\n", p1);

	// ES 7
	int i1 = 10, i2 = 20;
	printInt(&i1, &i2);

	// ES 8
	int a = 1, b = 2, c = 0;
	double x1, x2, *s2;
	bool f;
	void *s3;

	f = soluzioneEquazione(a, b, c, &x1, &x2);
	if (f) {
		printf("zeri della funzione: %lf %lf\n", x1, x2);
	} else {
		printf("la funzione non tocca l'asse x\n");
	}

	s2 = soluzioneEquazionePtr(a, b, c);
	if (s2) {
		printf("zeri della funzione: %lf %lf\n", *s2, *(s2 + 1));
	} else {
		printf("la funzione non tocca l'asse x\n");
	}

	s3 = soluzioneEquazionePtrComplessi(a, b, c);

	// ES 8b
	// printSoluzione(s3);

	// ES 9
	int i19 = 7, i29 = 24;
	int mcd = MCD(i19, i29);
	printf("mcd: %d\n", mcd);

	// ES 10
	int i10 = 7, i20 = 24;
	int m = mcm(i10, i20);
	printf("mcd: %d\n", m);

	// ES 11



	return 0;
}