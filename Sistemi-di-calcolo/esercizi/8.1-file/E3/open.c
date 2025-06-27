#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

int main() {
    // aprire il file miofile.txt (che non esiste)
    // creandolo con permessi: 
    //  - utente: lettura e scrittura
    //  - gruppo: lettura e esecuzione
    //  - altri: lettura
    // Poi chiudere il file

    // Se togli O_TRUNC il contenuto del file non viene eliminato all'apertura
    // echo "hello world " > miofile.txt ---> cat miofile.txt
    // Se togli O_CREAT se il file non esiste ottieni errore
    
    int fd = open("miofile.txt", O_CREAT | O_WRONLY | O_TRUNC, 0654);
    if (fd == -1) {
        perror("error in open");
        return EXIT_FAILURE;
    }
    int r = close(fd);
    if (r == -1) {
        perror("error in close");
        return EXIT_FAILURE;
    }
}