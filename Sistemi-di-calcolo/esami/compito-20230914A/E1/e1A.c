#include "e1A.h"

unsigned char* base64lessless(unsigned char *data, unsigned out_len, unsigned char* b64_table) {
    if (data == NULL || out_len == 0)
        return NULL;

    unsigned char* out = malloc(out_len);

    unsigned char bits_left = 0;
    unsigned char prev_bits = 0;
    
    // L'algoritmo considera i bit di data a gruppi di 6 bit,
    // usando il valore ottenuto come indice nella tabella
    // b64_table per derivare elementi dell'array di output

    int i;
    for (i = 0; i < out_len; ++i) {

        // ATTENZIONE: la sorgente di shl/shr puo' essere solo:
        //              - immediato
        //              - registro cl

        // SUGGERIMENTO: ricordare che i registri A, B, C, D
        //               offrono due "parti" (es. A: al, ah) 
        //               da 1 byte.

        unsigned char item = *data;

        // index richiede 6 bit dall'input

        // prendo bit rimasti dall'iterazione precedente
        unsigned char index = (prev_bits << (6 - bits_left));
        // bit mancanti da elemento attuale di data
        index = index | (item >> (2 + bits_left));

        // calcolo bit da utilizzare nella prossima iterazione
        bits_left = (8 - (6 - bits_left)) & 7;

        // bit rimasti da usare nella prossima iterazione
        unsigned char pos = (8 - bits_left);
        prev_bits = item << pos;
        prev_bits = prev_bits >> pos;
    
        // se rimangono 6 bit non devo spostarmi nell'array
        if (bits_left < 6) data += 1;

        // applico mapping
        out[i] = b64_table[index];
    }

    return out;
}
