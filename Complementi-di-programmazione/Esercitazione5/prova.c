#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int rows;
    int cols;
    float **mat;
} Mat;

Mat* mat_alloc(int rows, int cols) {
	Mat* m = (Mat *)malloc(sizeof(Mat));

	m->rows = rows;
	m->cols = cols;

	m->mat = (float **) malloc(sizeof(float*) * m->rows);

	for (int i=0; i<m->rows; i++) {
		m->mat[i] = (float *) malloc(sizeof(float) * m->cols);
	}

	return m;
}

void mat_print(Mat *m) {
	if (m == NULL) {
		return;
	}
	printf("%d %d\n", m->rows, m->cols);

	for (int i=0; i<m->rows; i++) {
		for (int j=0; j<m->cols; j++) {
			printf("%f\t", m->mat[i][j]);
		}
		printf("\n");
	}
}

Mat* mat_read(const char *filename) {
	int rows, cols;
	FILE *file = fopen(filename, "r");

	if (file == NULL) {
		printf("ERRORE NELL'APERTURA DEL FILE\n");
		exit(1);
	}

	fscanf(file, "%d %d", &rows, &cols);
	Mat *m = mat_alloc(rows, cols);

	float buff;
	int i=0, j=0;
	while(fscanf(file, "%f", &buff) != EOF) {
		m->mat[i][j] = buff;
		j++;
		if (j >= cols) {
			j = j%cols;
			i++;
		}
	}
	fclose(file);
	return m;
}

int main() {
    char *filename = "matrice.txt";
    Mat *m = mat_read(filename);

    printf("\nTEST ESERCIZIO 11\n");
    mat_print(m);
	
    return 0;
}