#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "e3.h"

// la funzione most_freq_char deve
// trovare il carattere più frequente in un
// array buf di nel caratteri

int main() {
    char buf1[] = "To be, or not to be: that is the question: "
                  "Whether 'tis nobler in the mind to suffer "
                  "the slings and arrows of outrageous fortune, or to take "
                  "arms against a sea of troubles, and by opposing end them.";
    int res = most_freq_char(buf1, sizeof(buf1));
    printf("Test 1: carattere più frequente: '%c' (ASCII %d)\n", res, res);

    char buf2[] = "The trooper";
    res = most_freq_char(buf2, sizeof(buf2));
    printf("Test 2: carattere più frequente: '%c' (ASCII %d)\n", res, res);

    return 0;
}
