#include <string.h>
#include <stdlib.h>

#define M 100000
#define N 10000
#include <stdio.h>

void init(int *v, int n) {
	memset(v, n*sizeof(int), 255);
}

void A(int *v, int n) {
	int i = 0;
	for (i=0; i<n; i++) v[i] = v[i] / 2;
}

void B(int *v, int n) {
	int i = 0;
	for (i=0; i<n; i++) v[i] = v[i] >> 1;
}

int main() {
	int* v = malloc(N*sizeof(int)), i;
	init(v, N);
	for (i=0; i<M; i++) {
		A(v, N);
		B(v, N);
	}
    printf("%d\n", v[0]);
	free(v);
	return 0;
}
