#ifndef __E2__
#define __E2__

struct destinazione {
    char destinazione[4];   	// Destinazione del collegamento
    int costo;              	// Costo del collegamento
    struct destinazione * next; // Puntatore a un altro elemento della stessa struttura
};

void destinazioniDisponibili(const char *, const char *, int, struct destinazione **);

#endif
