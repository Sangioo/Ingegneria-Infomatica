#include "aux.h"

bool indexValid(int i, int j, int rows, int cols) {
  	return 0 <= i && i < rows && 0 <= j && j < cols;
}

void applicaFiltro(Mat *src, Mat * filtro, int riga, int colonna){
  	for (int i=0; i<filtro->rows; i++) {
      	for (int j=0; j<filtro->cols; j++) {
          	int k = i+riga;
          	int l = j+colonna;
          	if (indexValid(k, l, src->rows, src->cols)) {
          		src->row_ptrs[k][l] *= filtro->row_ptrs[i][j];
            }
        }
    }
}

