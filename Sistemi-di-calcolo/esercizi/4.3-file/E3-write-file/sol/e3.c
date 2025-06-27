#include <stdio.h>
#include <assert.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>

#include "../e3.h"

#define USE_FILE 0

int getStudents(const char * filename, student * in_list, int min_mark){

	int result = 0;

#if USE_FILE
	FILE * fd = NULL;	
	fd = fopen(filename, "w");
	if (fd == NULL) return -1;
	
	// scorriamo la lista in ingresso
	student * temp = in_list;
	while (temp != 0){
		// controlliamo il voto dello studente. Se è maggiore o uguale a min_mark scriviamo il voto su file
		if (temp->mark >= min_mark) {
			int n = fprintf(fd, "%s %s - %d\n", temp->surname, temp->name, temp->mark);
			if (n < 0) { result = -1; break; }
		}
		temp = temp->next;
	}

	// Chiudiamo il file se è stato aperto
	if (fd != NULL) fclose(fd);

#else

	int fd = open(filename, O_CREAT | O_WRONLY, 0644 /* vedere lezione permessi file system */);
	if (fd < 0) return -1;
	
	// scorriamo la lista in ingresso
	student * temp = in_list;
	while (temp != 0){
		// controlliamo il voto dello studente. Se è maggiore o uguale a min_mark scriviamo il voto su file
		if (temp->mark >= min_mark) {
			char tmp[256];
			int n = snprintf(tmp, 256, "%s %s - %d\n", temp->surname, temp->name, temp->mark);
			if (n < 0 || n >= sizeof(tmp)) { // tmp e' troppo piccolo 
				result = -1; break;
			}
			int n2 = write(fd, tmp, n);
			if (n2 != n) { // errore durante la scrittura
				result = -1; break;
			}
		}
		temp = temp->next;
	}

	// Chiudiamo il file se è stato aperto
	if (fd >= 0) close(fd);
#endif

	return result;
}