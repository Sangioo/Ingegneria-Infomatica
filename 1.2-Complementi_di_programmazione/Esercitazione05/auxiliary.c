#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
#include "auxiliary.h"


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

void mat_init_bool(Mati *m) {
	for (int i=0; i<m->rows; i++) {
		for (int j=0; j<m->cols; j++) {
			m->mat[i][j] = rand() % 2;
		}
	}

	return;
}

void mat_print_int(Mati *m) {
	if (m == NULL) {
		return;
	}
	printf("%d %d\n", m->rows, m->cols);

	for (int i=0; i<m->rows; i++) {
		for (int j=0; j<m->cols; j++) {
			printf("%s ", m->mat[i][j]);
		}
		printf("\n");
	}
}

int mystrlen(char *s) {
	if (s == NULL) {
		return 0;
	}

	int len = 0;
	while (s[len] != '\0') {
		len++;
	}
	return len;
}