#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "e1.h"

// la funzione read_file deve allocare dinamicamente un buffer
// e caricarci dentro il contenuto di un file

int main() {

    void *buffer;
    size_t size;

    int res = read_file("file.dat", &buffer, &size);

    printf("---------\nTest 1: read %lu bytes with result %d\n---------\n", size, res);

    if (res == 0) {
        fwrite(buffer, 1, size, stdout);
        free(buffer);
    } else perror("Error");
    
    res = read_file("wrongfilename.dat", &buffer, &size);

    printf("\n---------\nTest 2: read %lu bytes with result %d\n---------\n", size, res);
    
    if (res == 0) {
        fwrite(buffer, 1, size, stdout);
        free(buffer);
    } else perror("Error");

    return 0;
}
