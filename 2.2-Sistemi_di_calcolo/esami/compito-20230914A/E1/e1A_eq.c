#include "e1A.h"

unsigned char* base64lessless(unsigned char *data, unsigned out_len, unsigned char* b64_table) {
    // unsigned char* eax = NULL;
    if (data == NULL)
        goto E;
    if (out_len == 0)
        goto E;
    
    unsigned char *esi = malloc(out_len);
    unsigned char dh = 0, dl = 0;

    int edi = 0;
L:
    if (edi >= out_len)
        goto E;

    unsigned char bl = *data;

    // index richiede 6 bit dall'input

    // prendo bit rimasti dall'iterazione precedente
    unsigned char cl = 6;
    cl -= dh;
    unsigned char ch = dl;
    ch = ch << cl;
    // bit mancanti da elemento attuale di data
    cl = 2;
    cl += dh;
    ch = ch | (bl >> cl);

    // calcolo bit da utilizzare nella prossima iterazione
    dh = (8 - (6 - dh)) & 7;

    // bit rimasti da usare nella prossima iterazione
    unsigned char pos = (8 - dh);
    dl = bl << pos;
    dl = dl >> pos;

    // se rimangono 6 bit non devo spostarmi nell'array
    if (dh < 6) data += 1;

    // applico mapping
    esi[edi] = b64_table[ch];

    edi++;
    goto L;
E:
    return esi;
}