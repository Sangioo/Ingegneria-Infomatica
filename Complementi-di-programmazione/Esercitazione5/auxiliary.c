#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
#include "aux.h"


void mat_init(Mat *m) {
	for (int i=0; i<m->rows; i++) {
		for (int j=0; j<m->cols; j++) {
			m->mat[i][j] = (float)rand()/(float)(RAND_MAX/100);
		}
	}

	return;
}

void mat_init_symmetric(Mat *m) {
	float val;
	for (int i=0; i<m->rows; i++) {
		for (int j=0; j<m->cols; j++) {
			val = (float)rand()/(float)(RAND_MAX/100);
			m->mat[i][j] = val;
			m->mat[j][i] = val;
		}
	}

	return;
}
