#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

#include "aux.h"


float somma_diag(Mat *mat, int row, int col) {
  	int rows = mat->rows, cols = mat->cols;
  	int diag_index = row-col;
  	float sum = 0.0;
	for (int i=0; i<rows; i++) {
    	for (int j=0; j<cols; j++) {
          	if (i-j != diag_index) continue;
          
          	sum += mat->mat[i][j];
        }
    }
  	return sum;
}
