#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include "aux.h"

Mat* mat_trasposta(Mat* m) {
	int rows = m->rows, cols = m->cols;
  	Mat *out = mat_alloc(rows, cols);
  	for (int i=0; i<rows; i++) {
    	for (int j=0; j<cols; j++) {
        	out->mat[i][j] = m->mat[j][i];
        }
    }
  	return out;
}

Mat* trasponi_e_massima_diagonale(Mat* m) {
	Mat *matrice = mat_trasposta(m);
  	int rows = matrice->rows, cols = matrice->cols;
  	Mat *out = mat_alloc(rows/2, cols/2);
    int max;
  	for (int i=0; i<rows/2+1; i++) {
    	for (int j=0; j<cols/2+1; j++) {
        	int somma = 0;
          	for (int k=0; k<rows/2; k++) {
            	for (int l=0; l<cols/2; l++) {
                	if (k == l)
                      	somma += matrice->mat[i+k][j+l];
                }
            }
          
          	if (somma > max) {
              	max = somma;
            	for (int k=0; k<rows/2; k++) {
            		for (int l=0; l<cols/2; l++) {
                      	out->mat[k][l] = matrice->mat[i+k][j+l];
                	}
            	}
            }
        }
    }
  	return out;
}
