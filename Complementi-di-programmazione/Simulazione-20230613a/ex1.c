#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

#include "aux.h"

void flip_riga(Mat *m) {
  	int rows = m->rows, cols = m->cols, temp;
	for (int i=0; i<rows; i++) {
      	if (i%2 == 1) continue;
      
      	temp = 0;
      	for (int j=0; j<cols/2; j++) {
          	temp = m->mat[i][j];
          	m->mat[i][j] = m->mat[i][cols-j-1];
          	m->mat[i][cols-j-1] = temp;
        }
    }
}

Mat* mat_copy(Mat *m) {
  	int rows = m->rows, cols = m->cols;
 	Mat *out = mat_alloc(rows, cols);
	for (int i=0; i<rows; i++) {
      	for (int j=0; j<cols; j++) {
          	out->mat[i][j] = m->mat[i][j];
        }
    }
  	return out;
}

int massimo_flip_riga(Mat *m){
  	Mat *matrice = mat_copy(m);
	flip_riga(matrice);
  	mat_print(matrice);
  	
  	int rows = matrice->rows, cols = matrice->cols;
  	int max = 0, sum;
  	for (int i=0; i<rows; i+=rows/2) {
      	for (int j=0; j<cols; j+=cols/2) {
          	sum = 0;
          	for (int k=0; k<rows/2; k++) {
            	for (int l=0; l<cols/2; l++) {
                	sum += matrice->mat[i+k][j+l];
                }
            }
          	printf("somma: %d\n", sum);
          	if (sum > max) {
              	max = sum;
            }
        }
    }
  
  	return max;
}
