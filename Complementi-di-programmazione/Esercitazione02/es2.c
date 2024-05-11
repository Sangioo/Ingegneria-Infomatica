// Date le seguenti variabili:

// short s;
// int i;
// long l;
// float f;
// double d;

// Scrivere un programma che legga in input dei valori per le suddette variabili e stampi il risultato delle seguenti espressioni:
// 1. s+10*l
// 2. (s+i)*l
// 3. (s+i)*l+f
// 4. s/f + sin(f)
// 5. l+1.5f
// 6. i<10
// 7. d * 3.14159

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

	printf("s+10*l: %ld\n", s+10*l);
	printf("(s+i)*l: %ld\n", (s+i)*l);
	printf("(s+i)*l+f: %lf\n", (s+i)*l+f);
	printf("s/f + sin(f): %lf\n", s/f + sin(f));
	printf("l+1.5f: %f\n", l+1.5f);
	printf("i<10: %d\n", i<10);
	printf("d*3.14159: %lf\n", d*3.14159);

	return 0;
}