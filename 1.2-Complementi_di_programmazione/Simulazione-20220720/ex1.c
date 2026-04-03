#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

#include "aux.h"

int* controlla_colonne(Mat *m, double w, double v){
  	int *out = (int *) malloc(sizeof(int) * m->rows);
  	int cols = m->cols, rows = m->rows;
  
  	for (int i=0; i<cols; i++) {
  		double media = 0;
    	for (int j=0; j<rows; j++) {
    		media += m->mat[j][i];
    	}
      	media = media / (double)rows;
      
      	if (w <= media && media <= v) {
          	out[i] = 1;
        } else {
          	out[i] = 0;
        }
  	}
  	return out;
}
