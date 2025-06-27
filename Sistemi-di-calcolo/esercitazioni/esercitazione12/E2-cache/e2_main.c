#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "e2.h"

#define N 100000000

double get_real_time_msec() {
	struct timespec ts;
	clock_gettime(CLOCK_MONOTONIC, &ts);
    return ts.tv_sec*1E03 + ts.tv_nsec*1E-06;
}

int main() {
    unsigned i;
    short *v = malloc(N*sizeof(short));
    for (i=0; i<N; ++i) v[i] = 1;
    double start, elapsed, elapsed_opt;
    long x;

    // versione non ottimizzata
    start = get_real_time_msec();
    x = f(v,N);
    elapsed = get_real_time_msec() - start;
    printf("Risultato versione non ottimizzata: %ld - Tempo: %f msec\n", x, elapsed);

    // versione ottimizzata
    start = get_real_time_msec();
    x = f_opt(v,N);
    elapsed_opt = get_real_time_msec() - start;
    printf("Risultato versione ottimizzata: %ld - Tempo: %f msec\n", x, elapsed_opt);

    printf("Speedup: %.2fx\n", elapsed/elapsed_opt);

    free(v);
    return EXIT_SUCCESS;
}
