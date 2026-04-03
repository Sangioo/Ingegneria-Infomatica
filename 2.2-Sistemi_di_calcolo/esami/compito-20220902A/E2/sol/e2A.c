#include "../e2A.h"
#include <stdio.h>
#include <assert.h>

void getStudents(const char * filename, student * in_list, int min_mark){
	FILE * fd = 0;	
	fd = fopen(filename, "w");
	assert(fd != NULL);
	
	//scorriamo la lista in ingresso
	student * temp = in_list;
	while (temp != 0){
		//controlliamo il voto dello studente. Se è maggiore o uguale a min_mark scriviamo il voto su file
		if (temp->mark >= min_mark)
			fprintf(fd, "%s %s - %d\n", temp->surname, temp->name, temp->mark);
		temp = temp->next;
	}

	//Chiudiamo il file se è stato aperto
	if (fd!=NULL) fclose(fd);
	return;
}
