#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "pgm.h"
#include "e2.h"

#define IN_PATH    "colosseo.pgm"
#define OUT_PATH   "colosseo-sfocato.pgm"
#define CTR_PATH   "colosseo-controllo.pgm"
#define TOLERANCE  1

unsigned compare(unsigned char* ctr, unsigned char* out, int w, int h){
    int i,j,u,v,delta;
    unsigned sum = 0;
    for (i=0; i<h; ++i)
        for (j=0; j<w; ++j){
            delta = (int)ctr[i*w+j] - (int)out[i*w+j];
            if (delta<0) delta = -delta;
            //printf("%u\n",delta);
            sum += (unsigned)delta/TOLERANCE;
    }
    return  (int)(100.0-100.0*sum/(256*h*w));
}

int main() {

    char *in_path = IN_PATH;
    char *out_path = OUT_PATH;
    char *ctr_path = CTR_PATH;
    int err;
    unsigned char *in, *out, *ctr;

    int h, w;

    // load image file in pgm format
    printf("Open image file: %s\n", in_path);
    err = pgm_load(&in, &h, &w, in_path);
    assert(!err);
    printf("Loaded imput %dx%d image\n", w, h);

    // load control image file in pgm format
    printf("Open image file: %s\n", ctr_path);
    err = pgm_load(&ctr, &h, &w, ctr_path);
    assert(!err);
    printf("Loaded control %dx%d image\n", w, h);

    // allocate out matrix
    out = malloc(h*w*sizeof(unsigned char));
    assert(out != NULL);

    // compute convolution filter
    blur5(in, out, w, h);

    // Compare output to control image
    unsigned res = compare(ctr, out, w, h);

    // save output image
    printf("    Saving image: %s\n", out_path);
    err = pgm_save(out, h, w, out_path);
    assert(!err);

    // cleanup
    free(in);
    free(ctr);
    free(out);

    printf("Risultato: %d/%d\n", res, 100);
}


