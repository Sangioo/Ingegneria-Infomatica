#include "e1A.h"

unsigned char fight(pokemon* p1, pokemon* p2)
{
    
    short pf1 = p1->pf;
    short pf2 = p2->pf;
    char res = 0;

    unsigned char i;
    for (i = 1; i <= 10; i++) {
        pf2 = update(i,p1,pf2);
        pf1 = update(i,p2,pf1);

        res = winner(pf1,pf2);
        if (res>=0)
            break;
        res = 0;

    }
    return (unsigned char) res;
}
