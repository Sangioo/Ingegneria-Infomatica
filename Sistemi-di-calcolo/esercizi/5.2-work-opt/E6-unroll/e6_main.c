#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <assert.h>
#include "e6.h"

#define N 10000
#define M 1000000

double get_real_time_msec() {
    struct timespec ts;
    clock_gettime(CLOCK_MONOTONIC, &ts);
    return ts.tv_sec*1E03 + ts.tv_nsec*1E-06;
}

int main(){

	int i, s = 0;
	
	int *v = malloc(N*sizeof(int));
	assert(v != NULL);
	
	memset(v, 1, N*sizeof(int));
	
	double start = get_real_time_msec();
	
	for (i=0; i<M; i++) s += sum(v,N);
		
	double elapsed = get_real_time_msec() - start;

	free(v);

	printf("Res=%X - Time=%f\n", s, elapsed);

	return 0;
}
