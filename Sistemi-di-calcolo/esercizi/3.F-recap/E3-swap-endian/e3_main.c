#include <stdio.h>
#include "e3.h"

int score, trials;

void test(unsigned n, int ok) {
    trials++;
    unsigned res = swap_endianness(n);
    printf("Test %d: swap_endianess(0x%X) = 0x%X ", trials, n, res);
    printf("[corretto: 0x%X]\n", ok);
    score += res == ok;
}

int main() {
    test(0xABADCAFE, 0xFECAADAB);
    test(0x12345678, 0x78563412);
    test(0x00000001, 0x01000000);
    test(0xABADADBA, 0xBAADADAB);

    printf("Risultato: %d/%d\n", score, trials);

    return 0;
}
