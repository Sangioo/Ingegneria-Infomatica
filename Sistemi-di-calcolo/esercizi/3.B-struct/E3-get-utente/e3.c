#include "e3.h"

void get_utente(char* privilegi, short* user_id) {
    stud_t utente;       // struttura allocata in stack
    curr_user(&utente);  //
    *privilegi = utente.privilegi;
    *user_id = utente.user_id;
}
