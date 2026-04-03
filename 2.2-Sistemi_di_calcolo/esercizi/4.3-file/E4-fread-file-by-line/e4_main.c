#include <stdio.h>
#include <stdlib.h>
#include "e4.h"

// la funzione read_file_by_line deve allocare dinamicamente un 
// array di stringhe e caricarci dentro il contenuto di un file, 
// riga per riga

int main() {

    int i, res;
    char** lines;
    int num_lines;
    
    res = read_file_by_line("file.dat", &lines, &num_lines);
    if (res != 0) {
        perror("Errore");
        return -1;
    }

    for (i=0; i<num_lines; ++i)
        printf("%d: %s\n", i, lines[i]);

    deallocate_lines(lines, num_lines);

    return 0;
}
