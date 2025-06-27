#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>

int main(){

    // diversi modi di scrivere sullo standard output

    char* str = "Hello world!\n";
    size_t len = strlen(str);

    // approccio #1
    printf("%s", str); 

    // approccio #2
    fprintf(stdout, "%s", str);

    // approccio #3
    write(1 /* file descriptor */, str, len);

    // approccio #4
    fwrite(str, 1, len, stdout);

    // NOTA: stdour e' una variabile globale definita da stdio.h

    // approccio #{2, 3, 4} possono essere facilmente
    // cambiati per lavorare sullo standard error
    // - file descriptor => 2
    // - FILE* => stderr

    return EXIT_SUCCESS;
}