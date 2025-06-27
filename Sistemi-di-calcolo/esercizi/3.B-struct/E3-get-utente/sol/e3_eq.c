#include "e3.h"

// typedef struct {         // base
//     char privilegi;      // offset: 0 |x.|    (base)
//     short user_id;       // offset: 2 |xx|   2(base)
// } stud_t;                // sizeof: 4


void get_utente(char* privilegi, short* user_id) {
    stud_t utente;          // struttura allocata in stack
    stud_t* edi = &utente;

    curr_user(edi);

    char* eax = privilegi;
    char dl = edi->privilegi;
    *eax = dl;

    short* ecx = user_id;
    short dx = edi->user_id;
    *ecx = dx;
}
