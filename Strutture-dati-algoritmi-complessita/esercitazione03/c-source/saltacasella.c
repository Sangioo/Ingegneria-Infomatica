#include <stdio.h>
#include <stdlib.h>

int saltacasella(int** mat, int i, int j, int n, int N);
static int driver(int** mat, int N);
static void stampamatrice(int** mat, int N);

long Cont = 0;

int saltacasella(int** mat, int i, int j, int n, int N) {
    return 3; /* no soluzione */
}


static int driver(int** mat, int N) {
    for(int i = 0; i < N; i++)
        for(int j = 0; j < N; j++) 
            if(saltacasella(mat, i, j, 1, N) == 0) return 0;
    return(3);
}

static void stampamatrice(int** mat, int N) {
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) printf("%4d", mat[i][j]);
        printf("\n");
    }
}

int main(int argc, char **argv) {
    if(argc != 2) {
        printf("./saltacasella <size>");
        exit(3);
    }
    int N = atoi(argv[1]);
    int **mat = malloc(N * sizeof(int*));
    for(int i = 0; i < N; i++) mat[i] = calloc(N, sizeof(int));
    if(driver(mat, N) == 0)
        stampamatrice(mat, N);
    else
        printf("\nnon trovato\n");
    return 0;
}