#ifndef __COUNTING_THREADS__
#define __COUNTING_THREADS__

typedef struct {
    unsigned int it;
    unsigned int val;
    unsigned int tid;
} thread_data_t;

unsigned int counting_threads(unsigned int th, unsigned int it, unsigned int val);

#endif