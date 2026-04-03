#ifndef __E3__
#define __E3__

typedef struct {         // base
    char privilegi;      // offset: 0 |x.|    (base)
    short user_id;       // offset: 2 |xx|   2(base)
} stud_t;                // sizeof: 4

void get_utente(char* privilegi, short* user_id);
void curr_user(stud_t *utente);

#endif
