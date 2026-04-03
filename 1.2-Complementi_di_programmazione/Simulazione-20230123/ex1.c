/*
Si scriva una funzione

Mat* massima_sottomatrice(Mat *m);

che data in input una matrice di interi m di dimensione 2Nx2N, restituisca la sottomatrice NxN di m la cui media degli elementi è massima.
Nota: in caso di stessa media restituire quella che ha il primo elemento nella matrice originale di indice riga minore, a parità di indice riga quello con anche indice colonna minore.

Esempio 1

m:
5 8
9 1

la sottomatrice 1x1 che ritorneremo è: 
9
la quale ha media 9.0, superiore a tutte le altre.

Esempio 2

m:
0 4 2 0
0 3 4 0
0 0 1 0
0 0 1 1

la sottomatrice 2x2 che ritorneremo è: 
4 2 
3 4 
la quale ha media 3.25, superiore a tutte le altre.
*/
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

#include "aux.h"


Mat* massima_sottomatrice(Mat *m){
    int N = m->rows/2;
    Mat *out = mat_alloc(N, N);
    float avg = 0;
    float max = 0;
	for (int i=N; i>=0; i--) {
        for (int j=N; j>=0; j--) {
            avg = 0;
            for (int k=0; k<N; k++) {
                for (int l=0; l<N; l++) {
                    avg += m->mat[i+k][j+l];
                }
            }
            avg = avg / (float)(N*N);
          	//printf("i: %d j: %d avg: %f\n", i, j, avg);

            if (avg >= max) {
              	max = avg;
                for (int k=0; k<out->rows; k++) {
                    for (int l=0; l<out->cols; l++) {
                        out->mat[k][l] = m->mat[i+k][j+l];
                    }
                }
            }
        }
    }
    return out;
}
