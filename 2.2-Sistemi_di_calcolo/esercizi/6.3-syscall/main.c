#include <stdio.h>

int main() {
    printf("sto per uscire dal programma con exit\n");
    myexit(1);
    printf("sono uscito\n"); //questa print non verrà mai eseguita dato che avrò eseguito la exit
    return 0;
}
