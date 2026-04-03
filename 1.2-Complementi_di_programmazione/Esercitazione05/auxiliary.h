#pragma once


typedef struct {
  int rows;
  int cols;
  float **mat;
} Mat;

typedef struct {
  int rows;
  int cols;
  int **mat;
} Mati;

/*FUNZIONI AUSILIARIE*/
void mat_init(Mat *m);

void mat_init_symmetric(Mat *m);

void mat_init_bool(Mati *m);

void mat_print_int(Mati *m);

int mystrlen(char *s);


/*ESERCIZIO 1*/
Mat* mat_alloc(int rows, int cols);

/*ESERCIZIO 2*/
void mat_free(Mat *m);

/*ESERCIZIO 3*/
void mat_print(Mat *m);

/*ESERCIZIO 4*/
Mat* mat_clone(Mat *m);

/*ESERCIZIO 5*/
bool mat_is_symmetric(Mat *m);

/*ESERCIZIO 6*/
void mat_normalize_rows(Mat *m);

/*ESERCIZIO 7*/
Mat* mat_sum(Mat *m1, Mat *m2);
Mat* mat_avg(Mat *m1, Mat *m2);

/*ESERCIZIO 8*/
Mat* mat_product(Mat *m1, Mat *m2);

/*ESERCIZIO 9*/
Mat* game_of_life(Mat* mat);

/*ESERCIZIO 10*/
void sort_strings(char **array);

/*ESERCIZIO 11*/
Mat* mat_read(const char *filename);

/*ESERCIZIO 12*/
void mat_write(const char *filename, Mat *m);
