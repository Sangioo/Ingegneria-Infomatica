#ifndef __E2__
#define __E2__

int getFirstEmptySlot (const char * filename, int len, char ** output);

//
// Funzione di supporto (gia implementate) che possono essere utilizzate
//

// calcola quanti minuti intercorrono tra time1 e time2 espressi come "hh:mm"
int calculateTimeDifference(const char* time1, const char* time2); 

// calcola un nuovo orario espresso come "hh:mm" aggiungendo minutesToAdd minuti a inputTime 
// il puntatore ritornato e' punta ad un buffer allocato malloc
char* addMinutesToTime(const char* inputTime, int minutesToAdd);  

#endif
