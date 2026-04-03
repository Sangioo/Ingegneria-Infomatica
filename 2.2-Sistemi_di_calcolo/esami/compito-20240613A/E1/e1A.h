#ifndef E1A_H
#define E1A_H

#include <stdlib.h>

unsigned char* deleetify(unsigned char* v, unsigned len);

// NOTE: se viene dato in input un carattere invalido, viene ritornato '*'
unsigned char deleetify_helper(unsigned char chr);

#endif // E1A_H