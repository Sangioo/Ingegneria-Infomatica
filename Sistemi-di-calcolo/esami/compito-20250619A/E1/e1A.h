#ifndef E1A_H
#define E1A_H

#include <stdlib.h>

typedef struct {
    unsigned short pf;
    unsigned char fast_damage;
    unsigned char main_damage;
    unsigned char countdown;
} pokemon;

unsigned char fight(pokemon* p1, pokemon* p2);
char winner (short pf1, short pf2);

short update (unsigned char turn, pokemon* attacker, short pf); 
#endif // E1A_H