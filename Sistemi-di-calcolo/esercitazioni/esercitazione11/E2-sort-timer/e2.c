#include "e2.h"
#include <signal.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

int i = 0;
int max = 0;

static void do_sort(int *v, int n) {
    int j;
    for (i=0; i<n; ++i) {
        for (j=1; j<n; ++j) {
            if (v[j-1] > v[j]) {
                int tmp = v[j-1];
                v[j-1] = v[j];
                v[j] = tmp;
            }
        }
    }
}

void handler(int signum) {
    printf("%f\%\n", 100.0 * (float) i / (float) max);
}

void sort(int *v, int n) {
    max = n;
    struct sigaction act = { 0 };
    act.sa_handler = handler;
    int ret = sigaction(SIGALRM, &act, NULL);
    if (ret == -1) {
        perror("errore sigaction!\n");
        exit(EXIT_FAILURE);
    }
    
    ualarm(1, 100000);
    do_sort(v, n);
    ualarm(0, 0);
}

