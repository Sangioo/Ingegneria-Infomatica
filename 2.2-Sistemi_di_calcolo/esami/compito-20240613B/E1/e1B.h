#ifndef E1B_H
#define E1B_H

void deleetify(unsigned char* v, unsigned len, unsigned char* res);

// NOTE: se viene dato in input un carattere invalido, chr viene settato a '*'
void deleetify_helper(unsigned char chr, unsigned char* out);

#endif // E1B_H