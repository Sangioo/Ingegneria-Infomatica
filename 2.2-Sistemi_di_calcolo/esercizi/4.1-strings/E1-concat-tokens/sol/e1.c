#include <string.h>
#include <stdlib.h>

#include "../e1.h"

#define DELIM ", ."

char* f(const char* s){
    // genero una copia di s
	// perche' strtok modifica
	// la stringa che gli passiamo
    size_t len = strlen(s);
    char* tmp = malloc(len+1);
    strcpy(tmp, s);

    // buffer che contiene 
	// la stringa finale
    // NOTA: uso calloc per impostare 
    //       terminatore di stringa
    char* res = calloc(1,len+1);

    // Estraggo sottostringa fino a
    // delimitatore con strtok e la
    // concateno usando strcat
    char* token = strtok(tmp, DELIM);
    while (token) {
        strcat(res, token);
        token = strtok(NULL, DELIM);
    }
    
    // dealloco la copia
    free(tmp);

    return res;
}
