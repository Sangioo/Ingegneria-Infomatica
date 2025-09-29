#ifndef E1B_H
#define E1B_H

#include <stdlib.h>


struct move;  // dichiarazione anticipata

typedef struct move {
    char name[8];
    unsigned char coord_in[2];  // [riga, colonna]
    struct move* next;
    unsigned char coord_fin[2];
} mossa;

unsigned char is_valid_move(mossa* m);
unsigned char check(mossa* head);

#endif // E1B_H