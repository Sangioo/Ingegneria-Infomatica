// Inserisci soluzione qui...

#include <stdio.h> // sscanf, sprintf

int convert_date(const char *input, char *output) {
    int giorno, mese, anno, res;

    res = sscanf(input, "%d/%d/%d", &giorno, &mese, &anno);
    if (res < 3) return -1;

    sprintf(output, "%d/%d/%d", mese, giorno, anno);
    if (res < 3) return -1;

    return 0;
}

