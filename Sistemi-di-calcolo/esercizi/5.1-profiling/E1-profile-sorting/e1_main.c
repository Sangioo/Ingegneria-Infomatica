#include "e1.h"
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <time.h>          // clock_gettime (misura nanosecondi)
#include <sys/resource.h>  // getrusage (misura microsecondi)

#ifndef NUM
#define NUM 30000 // provare con 5
#endif

long get_real_time_msec() {
	struct timespec ts;
	clock_gettime(CLOCK_MONOTONIC, &ts);
    return ts.tv_sec*1000 + ts.tv_nsec/1000000;
}

long get_user_time_msec() {
    struct rusage ru;
    getrusage(RUSAGE_SELF, &ru);
    return ru.ru_utime.tv_sec*1000 + ru.ru_utime.tv_usec/1000;
}

double get_sys_time_msec() {
    struct rusage ru;
    getrusage(RUSAGE_SELF, &ru);
    return ru.ru_stime.tv_sec*1000 + ru.ru_stime.tv_usec/1000;
}


int main(int argc, char* argv[]) {

    int n;
    long start_real, elapsed_real;
    long start_user, elapsed_user;
    long start_sys, elapsed_sys;

    if (argc < 2) n = NUM;
    else n = atoi(argv[1]);

    int i, *v = malloc(n*sizeof(int));
    assert(v != NULL);

    for (i=0; i<n; ++i) v[i] = n-i-1;

    printf("\nOrdinamento a bolle di %d int...\n-------------------------------\n", n);

    start_real = get_real_time_msec();
    start_user = get_user_time_msec();
    start_sys = get_sys_time_msec();
    sort(v, n);
    elapsed_real = get_real_time_msec() - start_real;
    elapsed_user = get_user_time_msec() - start_user;
    elapsed_sys = get_sys_time_msec() - start_sys;

    printf("Tempo reale richiesto da sort: %ld msec\n", elapsed_real);
    printf("Tempo user richiesto da sort: %ld msec\n", elapsed_user);
    printf("Tempo system richiesto da sort: %ld msec\n", elapsed_sys);

    free(v);

    return EXIT_SUCCESS;
}
