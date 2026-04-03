// Modificare l’esercizio 2 memorizzando il risultato delle espressioni in opportune variabili.
// Individuare dei valori di input che danno luogo a errori di approssimazione,troncamento e di
// overflow per il tipo di variabile di output scelta.
#include <stdio.h>
#include <math.h>

int main() {
	short s;
    int i;
    long l;
    float f;
    double d;

	printf("inserire s: ");
	scanf("%hd", &s);
	printf("inserire i: ");
	scanf("%d", &i);
	printf("inserire l: ");
	scanf("%ld", &l);
	printf("inserire f: ");
	scanf("%f", &f);
	printf("inserire d: ");
	scanf("%lf", &d);

	long prima = s+10*l;
	long seconda = (s+i)*l;
	double terza = (s+i)*l+f;
	double quarta = s/f + sin(f);
	float quinta = l+1.5f;
	int sesta = i<10;
	double settima = d*3.12159;

	printf("s+10*l: %ld\n", prima);
	printf("(s+i)*l: %ld\n", seconda);
	printf("(s+i)*l+f: %lf\n", terza);
	printf("s/f + sin(f): %lf\n", quarta);
	printf("l+1.5f: %f\n", quinta);
	printf("i<10: %d\n", sesta);
	printf("d*3.14159: %lf\n", settima);

	return 0;
}

// VALORI CHE DANNO ERRORI:
// 	- l:
// 		> 922337203685477580 - overflow
// 		