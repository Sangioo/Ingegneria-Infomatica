#include <stdio.h>
#include "e3.h"

void curr_user(stud_t *utente) {
    utente->privilegi = 0x06;
    utente->user_id = 565;
}

int main() {

    char privilegi;
    short user_id;

    get_utente(&privilegi, &user_id);

    printf("privilegi = 0x%X [ok: 0x06] - user_id = %hd [ok: 565]\n",
        (unsigned)privilegi, user_id);

    return 0;
}
