#pragma once

#include <string.h>

#define KEY_SIZE 16

void swap(unsigned char *a, unsigned char *b);
unsigned char rc4_helper(unsigned char *sbox, unsigned int i, unsigned char j);
void rc4_keyschedule(char *key, unsigned char *sbox);
void rc4(unsigned char *key, unsigned char *pt, unsigned char *ct);


void rc4_encrypt_rev(unsigned char *sbox, unsigned char *pt, unsigned char *ct);