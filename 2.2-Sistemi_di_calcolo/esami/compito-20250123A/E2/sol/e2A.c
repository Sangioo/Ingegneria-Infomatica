#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../e2A.h"

void getBooking(const char* input, char* out_date, char* out_time, char* char_duration) {
    // Estraggo dalla prenotazione la data
    strncpy(out_date, input + 30, 10);
    out_date[10] = '\0';
    // Estraggo dalla prenotazione l'ora
    strncpy(out_time, input + 40, 5);
    out_time[5] = '\0';
    // Estraggo dalla prenotazione la durata
    strncpy(char_duration, input + 45, 3);
    char_duration[3] = '\0';   
}

int getFirstEmptySlot (const char * filename, int len, char ** output){

	FILE* fp;
	*output = (char *) malloc((sizeof(char) * 17));

	// Apro il file
	fp = fopen(filename, "r");
	if (fp == NULL) return -1;

	char data_corrente [11];
	char ora_corrente [6];

	char data_tmp [11];
	char ora_tmp [6];
	char durata_tmp [4];
	
	int termina = 0;

	// Leggo il primo appuntamento disponibile
    char buf[50];
	char * ret = fgets(buf, sizeof(buf), fp);
	if (ret != NULL)
        getBooking(buf, data_tmp, ora_tmp, durata_tmp);

	// Ciclo su tutti i giorni possibili
	for (int d = 18; d < 23; d++) {
		// Calcolo la data attuale
		sprintf(data_corrente, "%02d/09/2023", d);
        // orario inizio della giornata
		strcpy(ora_corrente, "08:00");

		// Controllo se l'ultimo appuntamento letto dal file è per la data corrente
		while (strcmp(data_tmp, data_corrente) == 0) {

			// Controllo se c'e' spazio prima dell'ultimo appuntamento letto
			if (calculateTimeDifference(ora_corrente, ora_tmp) >= len) {
				sprintf(*output, "%s %s", data_corrente, ora_corrente);
				termina = 1;
				break;
			}

            // avanzo ora corrente
            char* tmp = addMinutesToTime(ora_tmp, atoi(durata_tmp));
			strcpy(ora_corrente, tmp);
            free(tmp);

			// Leggo l'appuntamento successivo
			ret = fgets(buf, sizeof(buf), fp);
			if (ret != NULL){
				getBooking(buf, data_tmp, ora_tmp, durata_tmp);
			} else {
				// Non ci sono ulteriori appuntamenti
                // data fittizia per non entrare nel while
				strcpy(data_tmp, "23/09/2023");
			}
		}

		if(termina == 1) break;

        // valutiamo se e' possibile inserire un appuntamento
        // in coda all'ultimo appuntamento della giornata
        // ma entro la fine della giornata
		if (calculateTimeDifference(ora_corrente, "18:00") >= len) {
			sprintf(*output, "%s %s", data_corrente, ora_corrente);
			termina = 1;
			break;
		}
	}

	// Chiudo il file
	fclose(fp);
    return termina == 1 ? 0 : -1;
}