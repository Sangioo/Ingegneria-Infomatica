#ifndef E1_H
#define E1_H

#define KEY_SIZE 16

void swap(unsigned char *a, unsigned char *b);
void rc4_helper(unsigned char *sbox, unsigned int i, unsigned char j, unsigned char *out);
void rc4_keyschedule(char *key, unsigned char *sbox);
void rc4(unsigned char *key, unsigned char *pt, unsigned char *ct);

void rc4_encrypt(unsigned char *sbox, unsigned char *pt, unsigned char *ct);

#endif