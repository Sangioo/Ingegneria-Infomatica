#include <stdio.h>
unsigned int is_valid(int i, int j, int w, int h);
unsigned char blurred(unsigned char* in, int w, int i, int j);

void blur5(unsigned char* in, unsigned char* out, int w, int h) {
    for (int i=0; i < h; i++) {
        for (int j=0; j < w; j++) {
            if (is_valid(i, j, w, h)){
                out[i*w + j] = blurred(in, w, i, j);
            } else {
                out[i*w + j] = in[i*w + j];
            }
        }
    }
}

unsigned int is_valid(int i, int j, int w, int h) {
    return (i-2) >= 0 && (i+2) < h && (j-2) >= 0 && (j+2) < w;
}

unsigned char blurred(unsigned char* in, int w, int i, int j) {
    unsigned int somma = 0;
    for (int k=-2; k<=2; k++) {
        for (int n=-2; n<=2; n++) {
            somma += in[(i+k)*w + (j+n)];
        }
    }
    return somma / 25;
}