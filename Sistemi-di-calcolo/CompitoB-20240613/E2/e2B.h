#ifndef __E2__
#define __E2__

struct connessione {
    char partenza[4];   	    // Partenza del collegamento
    char destinazione[4];   	// Destinazione del collegamento
    int costo;              	// Costo del collegamento
    struct connessione * next; // Puntatore a un altro elemento della stessa struttura
};

void destinazioniAcquistabili(struct connessione *, const char *, int, const char *);

#endif
