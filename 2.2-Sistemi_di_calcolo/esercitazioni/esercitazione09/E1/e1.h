#ifndef __E2__
#define __E2__

typedef struct person_t person_t;
struct person_t {
   char* name;
   char* surname;
   int year;       // anno di nascita
   int has_phd;    // 1 se ha il dottorato, altrimenti 0
   person_t* next;
};

int parseCSV(const char* file, person_t** out, int minAge);

#endif