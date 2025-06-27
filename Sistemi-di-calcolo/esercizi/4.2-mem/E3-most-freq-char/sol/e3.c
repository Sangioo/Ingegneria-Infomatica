#include "../e3.h"
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#include <stdio.h>
    
int most_freq_char(const char *buf, size_t nel) {
    // buffer che contiene un contatore per ogni carattere
    int i, *cnt = malloc(256*sizeof(int));
    assert(cnt != NULL);

    // inizializzo a zero tutti i contatori
    memset(cnt, 0, 256);

    // guardo tutti i caratteri dentro buf
    // e incremento il relativo contatore
    for (i=0; i<nel; ++i)
        cnt[buf[i]]++;
    
    // analizzo tutti i contatori per capire
    // quale carattere ha il contatore con
    // valore massimo
    int res = 0;
    for (i=1; i<256; ++i)
        if (cnt[i] > cnt[res]) 
            res = i;

    // libero il buffer dei contatori
    free(cnt);
    
    return res;
}
