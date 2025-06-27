#include "e4.h"
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

int trials, score;

void test(int *a, int *b, int n){

    // init variables & memory
    int i;
    div_rem_t *res = malloc(n*sizeof(div_rem_t));
    assert(res != NULL);
    trials++;

    printf("Trial %d:\n", trials);

    // call user-defined function
    array_div(a, b, res, n);

    for (i=0; i<n; ++i) {

        // get min and max
        int min = a[i] <  b[i] ? a[i] : b[i];
        int max = a[i] >= b[i] ? a[i] : b[i];

        // print human-readable result
        printf("   - %4d / %-4d = %-4d [corretto: %-4d]  [a=%-4d | b=%-4d | max=%-4d | min=%-4d]\n",
            max, min, res[i].quot, max / min, a[i], b[i], max, min);
        printf("   - %4d %% %-4d = %-4d [corretto: %-4d]\n",
            max, min, res[i].rem,  max % min);

        // compute score
        score += (res[i].quot == max / min) + (res[i].rem == max % min);
    }

    // cleanup
    free(res);
}


int main() {

    int a[] = { 2, 6, 17, 2, 99, 67, -14, -5, 12,  14 };
    int b[] = { 9, 6, 7, -122, 9,  67, -14, 18, 5, 19 };
    assert(sizeof(a) == sizeof(b));
    int n = sizeof(a) / sizeof(int);

    test(a, b, n);

    printf("Risultato: %d/%d\n", score, 2*n);
}
