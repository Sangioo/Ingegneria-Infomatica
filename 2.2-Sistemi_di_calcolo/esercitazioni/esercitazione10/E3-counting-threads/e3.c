#include <pthread.h>
#include <stdlib.h>

#include "e3.h"

unsigned int *shared_array;

void *mul(void *arg) {
    thread_data_t *a = (thread_data_t *)arg;
    shared_array[a->tid] = a->it * a->val;
}

unsigned int counting_threads(unsigned int th, unsigned int it, unsigned int val) {
    pthread_t threads[th];
    shared_array = (unsigned int *) malloc(th*sizeof(unsigned int));

    for (unsigned int i = 0; i < th; i++) {
        thread_data_t* arg = (thread_data_t *) malloc(sizeof(thread_data_t));
        arg->tid = i;
        arg->it = it;
        arg->val = val;

        pthread_create(threads + i, NULL, mul, arg);
    }

    unsigned int somma = 0;
    for (unsigned int i = 0; i < th; i++) {
        pthread_join(threads[i], NULL);
        somma += shared_array[i];
    }
    return somma;
}