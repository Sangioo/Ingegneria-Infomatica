#include "e5.h"

int f(int* v, int n) {
	int i, sum = 0;
	for (i=0; i<n; i++)
		sum += v[i];
	return sum;
}
