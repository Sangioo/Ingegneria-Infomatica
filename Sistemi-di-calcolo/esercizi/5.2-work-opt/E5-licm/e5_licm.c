#include "e5.h"

int licm(int* v, int n) {
	int i, sum = 0, x = f(v,n);
	for (i=0; i<n; i++)
		sum += x;
	return sum;
}
