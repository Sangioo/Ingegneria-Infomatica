#include "e3.h"

// typedef struct {         // base
//     char privilegi;      // offset: 0 |x.|    (base)
//     short user_id;       // offset: 2 |xx|   2(base)
// } stud_t;                // sizeof: 4

void get_utente(char* privilegi, short* user_id) {
    char* b = privilegi;
    short* di = user_id;
    stud_t utente;
    stud_t* si = &utente;
    curr_user(si);  //
    *b = si->privilegi;
    *di = si->user_id;
}
