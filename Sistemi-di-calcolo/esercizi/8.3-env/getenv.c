#include <stdlib.h>
#include <stdio.h>

int main() {
    //dare comando built-in env da shell e cambiare PATH
    //env visualizza le variabili d'ambiente definite nella shell corrente
    char* s = getenv("PATH");
    if (s) {
        printf("PATH=%s\n", s);
    }
    return 0;
}