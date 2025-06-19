#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "e1A.h"

#define MAX_BUFF 1024

int score, trials;

static unsigned char* to_string(unsigned char *v, int length, unsigned char* out)
{
    int i = 0, curr = 0;
    for (i = 0; i < length; i++) {
        curr += sprintf(out + curr, "%d", v[i]);
        if (i != length - 1) 
            curr += sprintf(out + curr, ",");
    }
    return out;
}

void swap(unsigned char *a, unsigned char *b)
{
    unsigned char tmp = *a;
    *a = *b;
    *b = tmp;
}

void rc4_helper(unsigned char *sbox, unsigned int i, unsigned char j, unsigned char *out)
{
    swap(&sbox[i % 256], &sbox[j]);
    *out = sbox[(sbox[i % 256] + sbox[j]) % 256];
}

void rc4_keyschedule(char *key, unsigned char *sbox)
{
    int i, j = 0;

    for(i = 0; i < 256; i++)
        sbox[i] = i;

    for(i = 0; i < 256; i++) {
        j = (j + sbox[i] + key[i % KEY_SIZE]) % 256;
        swap(&sbox[i], &sbox[j]);
    }
}

void rc4(unsigned char *key, unsigned char *pt, unsigned char *ct)
{
    unsigned char sbox[256];
    rc4_keyschedule(key, sbox);
    rc4_encrypt(sbox, pt, ct);
}

void test(unsigned char *key, unsigned char *pt, unsigned char *exp_ct) {
    trials++;
    int len = strlen(pt);
    unsigned char ct[len];
    unsigned char out[MAX_BUFF] = {0};
    rc4(key, pt, ct);
    int ok = memcmp(exp_ct, ct, len) == 0;
    printf("Test %d: ", trials);
    printf("risultato={%s} vs ", to_string(ct, len, out));
    printf("atteso={%s} -> ", to_string(exp_ct, len, out));
    printf("%s\n", ok ? "OK" : "KO");
    score += ok;
}

int main(int argc, char *argv[])
{
    unsigned char key[] = "iloveassembly!!!";

    test(key, "", "");
    test(key, "s", "\xe3");
    test(key, "sistemidicalcolo", "\xe3\xdc\xf4\x50\x41\xad\x22\x5e\x19\x84\x39\x75\x94\x51\x5f\xbe");

    printf("Risultato: %d/%d\n", score, trials);

    return 0;
}
