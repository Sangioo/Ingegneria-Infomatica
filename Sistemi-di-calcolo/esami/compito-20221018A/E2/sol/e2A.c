#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <unistd.h>

int loadStringsFromFile (const char * filename, char *** list){
	// Apriamo il file
	FILE * fd = fopen(filename, "r");
    if (fd == NULL) return 0;
	
	// Contiamo quante righe contiene valide e quanti caratteri contiene la riga più lunga
	int num_righe = 0, num_caratteri = 0, max_num_caratteri = 0;
	int riga_valida = 0, nuova_riga = 1;
	char c;
	for (c = getc(fd); c != EOF; c = getc(fd)) {
		if (nuova_riga==1 && isalpha(c)) {
			riga_valida=1;
			num_righe++;
		}
		num_caratteri++;
        if (c == '\n') {
			if (num_caratteri > max_num_caratteri) max_num_caratteri = num_caratteri;
			nuova_riga = 1;
			num_caratteri = 0;
			riga_valida = 0;
		} else nuova_riga = 0;
	}
	if (num_caratteri > max_num_caratteri) max_num_caratteri = num_caratteri;

	// Allochiamo un array di stringhe grande a sufficienza
	char ** strings = malloc(num_righe * sizeof(char*));
	// Per ogni riga letta
	fseek(fd,0,SEEK_SET);
	char * buf = malloc((max_num_caratteri+1)*sizeof(char));
	int i=0;
	while(num_righe > 0 && fgets(buf, max_num_caratteri+1, fd) != NULL) {
		if(isalpha(buf[0])) {
			// Cancello il carattere di ritorno a capo
			if (buf[strlen(buf)-1]=='\n') buf[strlen(buf)-1]='\0';
			// Allochiamo una stringa della giusta dimensione
			strings[i] = malloc((strlen(buf)+1) * sizeof(char));
			// Copiamo dal buffer di lettura nell'array finale
			strcpy(strings[i],buf);
			i++;
		}
	}

	// Restituiamo il numero di stringhe lette
	fclose(fd);
	*list = strings;
	return i;
}