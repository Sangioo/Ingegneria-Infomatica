#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "e2.h"

#define NUM 80000

int main() {

    int i, *v = malloc(NUM*sizeof(int));
    assert(v != NULL);

    for (i=0; i<NUM; ++i) v[i] = NUM-i-1;

    printf("\nstart sorting...\n-------------------------------\n");

    sort(v, NUM);

    printf("-------------------------------\n");
    for (i=0; i<10; ++i) 
        printf("v[%d]=%d\n", i, v[i]);

    free(v);
    
    return EXIT_SUCCESS;
}
