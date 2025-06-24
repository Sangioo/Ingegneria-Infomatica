#include "../e4.h"
#include <stdio.h>

int convert_date(const char *input, char *output) {
    int first, second, year;
    // estraggo dalla stringa i tre interi
    int res = sscanf(input, "%d/%d/%d", &first, &second, &year);
    // crea nuova stringa inserendo i tre interi
    sprintf(output, "%d/%d/%d", second, first, year);
    return res == 3 ? 0 : -1;
}
