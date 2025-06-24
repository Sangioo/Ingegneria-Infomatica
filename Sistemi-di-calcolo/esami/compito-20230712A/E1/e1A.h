#ifndef E1_H
#define E1_H

#include <stdlib.h>

void get_adler_constant(unsigned* v);
unsigned adler32(unsigned char *data, unsigned len);

#endif // E1_H