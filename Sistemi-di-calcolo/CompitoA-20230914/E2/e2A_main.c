#include "e2A.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

/*** NON MODIFICARE PER NESSUNO MOTIVO IL CODICE CHE SEGUE ***/

int calculateTimeDifference(const char* time1, const char* time2) {
    int hours1, minutes1, hours2, minutes2;

    // Analizza le due stringhe per estrarre ore e minuti
    sscanf(time1, "%d:%d", &hours1, &minutes1);
    sscanf(time2, "%d:%d", &hours2, &minutes2);

    // Calcola la differenza in minuti
    int totalMinutes1 = hours1 * 60 + minutes1;
    int totalMinutes2 = hours2 * 60 + minutes2;
    int difference = totalMinutes2 - totalMinutes1;

    return difference;
}

char* addMinutesToTime(const char* inputTime, int minutesToAdd) {
    int hours, minutes;
    sscanf(inputTime, "%d:%d", &hours, &minutes);

    // Calcola il nuovo orario
    int totalMinutes = hours * 60 + minutes;
    totalMinutes += minutesToAdd;

    // Assicurati che l'orario rimanga all'interno di una giornata (0-1439 minuti)
    totalMinutes = (totalMinutes + 1440) % 1440;

    // Estrai le nuove ore e i nuovi minuti
    hours = totalMinutes / 60;
    minutes = totalMinutes % 60;

    // Alloca spazio per la stringa risultante nel formato "hh:mm"
    char* resultTime = (char*) malloc(6 * sizeof(char));

    // Formatta la stringa risultante
    sprintf(resultTime, "%02d:%02d", hours, minutes);

    return resultTime;
}

int score, trials;

static void test(const char* filename, int num, int ret, const char * correct) {
    trials++;
    char * out = NULL;
    int val = getFirstEmptySlot(filename, num, &out);
    int ok = val == ret && (ret == 0 ? strcmp(correct, out) == 0 : 1);
    printf("Test %d - stringa generata: ottenuta=\"%s\" attesa=\"%s\" => %s\n", 
        trials, 
        val == 0 ? out : "", 
        ret == 0 ? correct : "",
        ok ? "OK" : "errore");
    if (out) free(out);
    score += ok;
}

int main() {
    test("booked1.txt", 120, 0, "18/09/2023 08:00");
    test("booked2.txt", 420, 0, "20/09/2023 08:00");
    test("booked1.txt", 600, -1, "");
    test("booked3.txt", 100, -1, "");
    printf("Risultato: %d/%d\n", score, trials);

    return EXIT_SUCCESS;
}
